/*
* Author : VERDU Rida - 2021
*/
#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <vector>
#include <string>
#include <iostream>

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

SerialPort* _InitSerialPort()
{
	//load dllinto addr space of client proc
	HMODULE hDLL = LoadLibraryExW(LR"(..\..\DriverCore\bin\DriverCore.dll)", nullptr, 0);
	if (!hDLL) {
		return nullptr;
	}

	//Resolve Objects Addr
	using GreetingType = SerialPort * (__cdecl*)(); //type def ptr to func w/ retType<void> argv/c<void>
	GreetingType pSerialPort = reinterpret_cast<GreetingType>(GetProcAddress(hDLL, "CreateSerialPort"));
	if (!pSerialPort) {
		return nullptr;
	}
	return pSerialPort();
}

std::string readSerialBuffer(SerialPort* LPCSerialPort, const std::size_t buffer_size)
{
	char* Buffer = new char[buffer_size];
	std::string strBuff;
	if (LPCSerialPort->readSerialPort(Buffer, buffer_size)) 
	{
		strBuff = Buffer;
		strBuff = strBuff.substr(0, buffer_size);
		for(int i(0); i < strBuff.size(); i++)
		{
			strBuff[i] = (char(abs(int(strBuff[i]))));
			std::cout << << std::endl;
		}
		delete[] Buffer;
		std::cout << strBuff << std::endl;
		return strBuff;
	}
	delete[] Buffer;
	return "";
}