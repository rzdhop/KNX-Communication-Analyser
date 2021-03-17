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
* project of the 2nd year BTECH HND at Dirderot High School
* during the year 2021 
*/

#define WIN32_LEAN_AND_MEAN
#define BAUDRATE 9600
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

#include "DriverCore.h"
#include <iostream>
#include <windows.h>
#include <string>

extern "C" __declspec(dllexport) SerialPort * __cdecl CreateSerialPort()
{
	return new SerialPort();
}

SerialPort::SerialPort()
{
	this->_errors = 0;
	this->_status = { 0 };
	this->_connState = FALSE;

	//debug cond
	this->_autoSelectPort(this->_SerialList());

	std::cout << "[*] Port name: " << this->_portName << std::endl;

	//Init I/O stream windows handler
	this->_streamHandle = CreateFileA(this->_portName.c_str(), GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (this->_streamHandle == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			std::cout << "[-] ERROR: Handle was not attached. Reason: " << this->_portName << " not available\n";
		}
		else { std::printf("[-] Undefined Error ! %d \n", GetLastError()); return; }
	}

	//Declare pointer to LPDCB struct (serialCOM parameters)
	DCB dcbSerialParameters = { 0 };

	if (!GetCommState(this->_streamHandle, &dcbSerialParameters)) {
		std::cout << "[-] Failed to retreive current serial parameter ! \n";
		return;
	}
	else {
		//Define dcbSerialParameters struct's parameter
		dcbSerialParameters.BaudRate = CBR_9600;
		dcbSerialParameters.ByteSize = 8;
		dcbSerialParameters.StopBits = ONESTOPBIT;
		dcbSerialParameters.Parity = NOPARITY;
		dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

		if (!SetCommState(this->_streamHandle, &dcbSerialParameters)) {
			std::cout << "[-] ERROR: could not set Serial port parameters" << GetLastError() << std::endl;
			return;
		}
		else {
			this->_connState = true;

			//Clean the buffers of this->_portName
			PurgeComm(this->_streamHandle, PURGE_RXCLEAR | PURGE_TXCLEAR); //flag : input clean | output Clean
		}
	}
}

SerialPort::~SerialPort()
{
	if (this->_connState)
	{
		this->_connState = FALSE;
		this->_CloseConn();
	}
}
void SerialPort::_CloseConn()
{
	std::cout << "[+] closing port";
	if (!this->_connState) CloseHandle(this->_streamHandle);
	else std::cout << "[-] There is no connection to Terminate \n";
	return;
}
int SerialPort::readSerialPort(char* buffer, unsigned int buf_size)
{
	DWORD bytesRead;
	DWORD toRead = 0;

	//Clear error flag (to avoid I/O blocking due to error)
	ClearCommError(this->_streamHandle, &this->_errors, &this->_status);

	if (this->_status.cbInQue > 0) { //check the number of bytes received but not read by ReadFile
		if (this->_status.cbInQue > buf_size) {
			toRead = buf_size;
			//Read Bytes from serial
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
		QueryDosDeviceA(serialList.back().c_str(), bufferPathFriendlyName, 5000);

		physicalDeviceObjectName = bufferPathFriendlyName;
		lastPos = physicalDeviceObjectName.find_last_of(R"(\)");
		physicalDeviceObjectName = physicalDeviceObjectName.substr(lastPos + 1);

		std::cout <<"[+] Friendly Name : |"  << physicalDeviceObjectName << "| --- Full Path : " << bufferPathFriendlyName << std::endl;
		
		if (!strcmp(physicalDeviceObjectName.c_str(), "ProlificSerial0") || !strcmp(physicalDeviceObjectName.c_str(), "VCP0") || !strcmp(physicalDeviceObjectName.c_str(), "USBSER000"))
		{
			this->_portName = serialList[i];
			return;
		}
		serialList.pop_back();
	}
	return;
}
std::vector<std::string> SerialPort::_SerialList()
{
	std::vector<std::string> serialList;
	std::string COMName("COM"), queryName("");
	char bufferTragetPath[5000];
	std::size_t path_size(0);

	//test each COM name to get the one used by the system and get his description name
	for (int i(0); i < 255; i++)
	{
		queryName = COMName + std::to_string(i);
		//Query the path of the COMName
		path_size = QueryDosDeviceA(queryName.c_str(), bufferTragetPath, 5000);
		if (path_size != 0) {
			serialList.push_back(queryName);
		}
	}
	return serialList;
}