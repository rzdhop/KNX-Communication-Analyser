#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "..\..\DriverCore\src\DriverCore.h"

int main()
{
	std::vector<std::string>receivedChar;
	//load dllinto addr space of client proc
	HMODULE hDLL = LoadLibraryExW(LR"(..\..\DriverCore\DriverCore.dll)", nullptr, 0);
	if (!hDLL) {
		std::cout << "Cannot load DLL ! " << GetLastError();
		return ERROR;
	}

	//Resolve Objects Addr
	using GreetingType = SerialPort * (__cdecl*)(); //type def ptr to func w/ retType<void> argv/c<void>
	GreetingType pSerialPort = reinterpret_cast<GreetingType>(GetProcAddress(hDLL, "CreateSerialPort"));
	if (!pSerialPort) {
		std::cout << "Cannot load Function ! " << GetLastError();
		return ERROR;
	}
	SerialPort* CSerialPort = pSerialPort();
	
#define BUFF_SIZE 8

	char Buffer[BUFF_SIZE];
	std::string strBuff;
	if (CSerialPort->readSerialPort(Buffer, BUFF_SIZE))
	{
		strBuff = Buffer;
	}

	return 0;
}