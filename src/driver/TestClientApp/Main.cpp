#include "pch.h"
#include <Windows.h>
#include <iostream>
#include "DriverCore.h"

int main()
{
	//load dllinto addr space of client proc
	HMODULE hDLL = LoadLibraryExW(L"DriverCore.dll", nullptr, 0);
	if (!hDLL) {
		std::cout << "Cannot load DLL !";
		return ERROR;}

	//Resolve Objects Addr
	using GreetingType = SerialPort* (__cdecl*)(); //type def ptr to func w/ retType<void> argv/c<void>
	GreetingType pSerialPort = reinterpret_cast<GreetingType>(GetProcAddress(hDLL, "CreateSerialPort"));
	if (!pSerialPort) {
		std::cout << "Cannot load Function !";
		return ERROR;
	}
	SerialPort* CSerialPort = pSerialPort();
	
	CSerialPort->HelloWorld();


	return 0;
}