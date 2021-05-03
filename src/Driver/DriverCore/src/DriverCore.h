/*
* Author : VERDU Rida - 2021
*/
#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

//Definition de la class SerialPort contenant mes fonction pour gérer la communication avec le modudule
class SerialPort
{
private:
	HANDLE _streamHandle;
	bool _connState;
	std::string _portName;
	COMSTAT _status;
	DWORD _errors;
public:
	SerialPort();
	~SerialPort();
	virtual void _CloseConn();
	virtual bool isConnected();
	virtual std::vector<std::string> _SerialList();
	virtual void _autoSelectPort(std::vector<std::string> serialList);
	virtual int readSerialPort(char* buffer, unsigned int buf_size);
};

//Fonction d'Initialisation de la class SeriaPort dans le DLL
SerialPort* _InitSerialPort()
{
	//Charge le DLL dans l'espace d'adresse du processus client
	HMODULE hDLL = LoadLibraryExW(LR"(..\..\DriverCore\bin\DriverCore.dll)", nullptr, 0);
	if (!hDLL) {
		return nullptr;
	}

	//Defini le type et le format du code associé au symbol de la class du DLL
	using GreetingType = SerialPort * (__cdecl*)(); //type def ptr vers func w/ retType<void> argv/c<void>
	GreetingType pSerialPort = (GreetingType)GetProcAddress(hDLL, "CreateSerialPort");
	if (!pSerialPort) {
		return nullptr;
	}
	return pSerialPort();
}

//Api de la class SerialPort pour facilité sont utilisation
std::string readSerialBuffer(SerialPort* LPCSerialPort, const std::size_t buffer_size)
{
	char* Buffer = new char[buffer_size];
	std::string strBuffer;
	if (LPCSerialPort->readSerialPort(Buffer, buffer_size)) 
	{
		strBuffer = Buffer;
		std::string strFlagBuffer = Buffer;
		strFlagBuffer = strFlagBuffer.substr(0, buffer_size);
		strBuffer = strBuffer.substr(0, buffer_size);
		auto strBufferSize = strBuffer.size();
		strBuffer = "";
		std::stringstream strhexBufffer;

		for (int i(0); i < strBufferSize; i++)
		{
			strhexBufffer << std::hex << abs(int(strFlagBuffer[i]));
			strBuffer += strhexBufffer.str();
			strhexBufffer.str(std::string());
		}
		std::cout << strBuffer;
		delete[] Buffer;
		return strBuffer;
	}
	delete[] Buffer;
	return "";
}