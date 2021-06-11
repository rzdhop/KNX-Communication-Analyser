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
#include <ctime>
#include "..\..\..\Traitement\src\logs.hpp"

//Definition de la class SerialPort contenant mes fonction pour gérer la communication avec le modudule
class SerialPort
{
private:
	HANDLE _streamHandle;
	bool _connState;
	std::string _portName;
	DWORD _errors;
	Logs log;
	std::ostringstream writeLogsStream;
public:
	COMSTAT _status;
	SerialPort();
	~SerialPort();
	virtual void _CloseConn();
	virtual bool isConnected();
	virtual std::vector<std::string> _SerialList();
	virtual void _autoSelectPort(std::vector<std::string> serialList);
	virtual int readSerialPort(char* buffer, unsigned int buf_size);
};

//Fonction d'Initialisation de la class SeriaPort dans le DLL
SerialPort* _InitSerialPort(std::string dll_Path)
{
	//Charge le DLL dans l'espace d'adresse du processus client
	HMODULE hDLL = LoadLibraryExA((LPCSTR)dll_Path.c_str(), nullptr, 0);
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
void readSerialBuffer(SerialPort* LPCSerialPort, std::string &containerFrame, const std::size_t buffer_size = 1)
{
	char* Buffer = new char[buffer_size];
	std::string strBuffer;
	std::size_t strBufferSize =0;
	bool flag = 0;
	std::clock_t begin = 0;
	while (1)
	{
		if (LPCSerialPort->readSerialPort(Buffer, buffer_size) > 0)
		{	
			if (!flag){
				begin = clock();
				flag = 1;
			}
			strBuffer = Buffer;
			if(strBuffer.size() == 0) strBuffer = "00";
			std::string strFlagBuffer = Buffer;
			strFlagBuffer = strFlagBuffer.substr(0, buffer_size);
			strBuffer = strBuffer.substr(0, buffer_size);
			strBufferSize = strBuffer.size();
			strBuffer = "";
			std::stringstream strhexBufffer;
			for (int i(0); i < strBufferSize; i++)
			{
				strhexBufffer << std::hex << int(strFlagBuffer[i]);
				if (strhexBufffer.str() == "0") containerFrame += "0";
				if (strhexBufffer.str().size() >= 8){
					containerFrame += strhexBufffer.str().substr(6, strhexBufffer.str().size());
					continue;
				}
				containerFrame += strhexBufffer.str();
			}
			strhexBufffer.str(std::string());
		}
		if (clock() - begin >= 200 && begin != 0 && (!LPCSerialPort->_status.cbInQue || LPCSerialPort->_status.cbInQue == 20))
		{
			for (int i=0; i< containerFrame.size(); i++) containerFrame[i] = toupper(containerFrame[i]);
			break;
		}
			
	}
	delete[] Buffer;
}