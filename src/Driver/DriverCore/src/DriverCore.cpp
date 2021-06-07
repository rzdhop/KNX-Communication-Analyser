/*
* Author : VERDU Rida 
*
* This DLL has been developped to be implemented into the main
* application. 
* This DLL Conain :
*	- Exportation of SerialPort* class
* 	- Methods od SerialPort
*
* This DLL has been developped by VERDU Rida (20yo) for a final
* project of the 2nd year BTECH HND at Diderot High School
* during the year 2021 
*/

#define WIN32_LEAN_AND_MEAN
#define BAUDRATE 9600
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

#include "../../Traitement/src/logs.hpp"
#include "DriverCore.h"
#include <iostream>
#include <windows.h>
#include <string>

//Declare l'exportation de CreateSerialPort en symbol pour sa future Implementation
extern "C" __declspec(dllexport) SerialPort * __cdecl CreateSerialPort()
{
	return new SerialPort();
}

//Constructeur de la class SerialPort
SerialPort::SerialPort()
{
	this->_errors = 0;
	this->_status = { 0 };
	this->_connState = FALSE;

	//Fonction permettat de selectionner le port connecté au module
	this->_autoSelectPort(this->_SerialList());

	//Initialisation des flux I/O de windows pour la lecture les donnée reçus de la carte
	this->_streamHandle = CreateFileA(this->_portName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (this->_streamHandle == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			//***********************ERROR************************
			std::cout << "[-] ERROR: Handle was not attached. Reason: " << this->_portName << " not available\n";
		}
		else {
			//***********************ERROR************************
			std::printf("[-] Undefined Error ! %d \n", GetLastError());
			return; }
	}

	//Declare le pointer vers LPDCB struct (parametre du Serial COM)
	DCB dcbSerialParameters = { 0 };

	if (!GetCommState(this->_streamHandle, &dcbSerialParameters)) {
		//***********************ERROR************************
		std::cout << "[-] Failed to retreive current serial parameter ! \n";
		return;
	}
	else {
		//Defini les parametre de la structure dcbSerialParameters
		dcbSerialParameters.BaudRate = CBR_9600;
		dcbSerialParameters.ByteSize = 8;
		dcbSerialParameters.StopBits = ONESTOPBIT;
		dcbSerialParameters.Parity = NOPARITY;
		dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

		if (!SetCommState(this->_streamHandle, &dcbSerialParameters)) {
			//***********************ERROR************************
			std::cout << "[-] ERREUR: Impossible d'appliqué les parametre de communication au Serial COM" << GetLastError() << std::endl;
			return;
		}
		else {
			this->_connState = true;

			//Vide le buffers du flux de communication serial 
			PurgeComm(this->_streamHandle, PURGE_RXCLEAR | PURGE_TXCLEAR); //flag : input clean | output Clean
		}
	}
}

//Destructeur fermant la connection et le flux de communication
SerialPort::~SerialPort()
{
	if (this->_connState)
	{
		this->_connState = FALSE;
		this->_CloseConn();
	}
}
//Methode effectuant la fermeture de la communication serial
void SerialPort::_CloseConn()
{
	std::cout << "[+] Fermeture des ports";
	if (!this->_connState) CloseHandle(this->_streamHandle);
	else {
		//***********************ERROR************************
		std::cout << "[-] Aucune communication a terminé \n";
	}
	return;
}
//lit et stock les données reçus du serial dans le buffer en parametre
int SerialPort::readSerialPort(char* buffer, unsigned int buf_size)
{
	DWORD bytesRead;
	DWORD toRead = 0;

	//Clear error flag (Pour eviter erreur de lecture)
	ClearCommError(this->_streamHandle, &this->_errors, &this->_status);

	if (this->_status.cbInQue > 0) { //Verifie le nombre de bytes reçus mais non-lu 
		if (this->_status.cbInQue > buf_size) {
			toRead = buf_size;
			//Lit et stock les bytes non-lu
			if (ReadFile(this->_streamHandle, buffer, toRead, &bytesRead, NULL)) return bytesRead;
		}
		else toRead = this->_status.cbInQue;
	}

	return 0;
}
bool SerialPort::isConnected()
{
	return this->_connState;
}
void SerialPort::_autoSelectPort(std::vector<std::string> serialList)
{
	auto numberOfSerial = serialList.size();
	if (!numberOfSerial) {return;}
	char bufferPathFriendlyName[5000]; 
	std::string physicalDeviceObjectName;
	std::size_t lastPos;

	for (size_t i(0); i < numberOfSerial; i++)
	{
		//Interoge le kernel sur le friendly name des ports serial connecter au system
		QueryDosDeviceA(serialList.back().c_str(), bufferPathFriendlyName, 5000);

		physicalDeviceObjectName = bufferPathFriendlyName;
		lastPos = physicalDeviceObjectName.find_last_of(R"(\)");
		physicalDeviceObjectName = physicalDeviceObjectName.substr(lastPos + 1);
		
		//verifie qu'il s'agit bien du port COM attendu
		if (!strcmp(physicalDeviceObjectName.c_str(), "ProlificSerial0") || !strcmp(physicalDeviceObjectName.c_str(), "VCP0") || !strcmp(physicalDeviceObjectName.c_str(), "USBSER000"))		{
			this->_portName = serialList[i];
			return;
		}
		serialList.pop_back();
	}
	return;
}
//Liste tout les ports COM connecté au system
std::vector<std::string> SerialPort::_SerialList()
{
	std::vector<std::string> serialList;
	std::string COMName("COM"), queryName("");
	char bufferTragetPath[5000];
	std::size_t path_size(0);

	//Teste chacun des COM possible et recupère sa description
	for (int i(0); i < 255; i++)
	{
		queryName = COMName + std::to_string(i);
		//Query le chemin d'acces du port COM
		path_size = QueryDosDeviceA(queryName.c_str(), bufferTragetPath, 5000);
		if (path_size != 0) {
			serialList.push_back(queryName);
		}
	}
	return serialList;
}
