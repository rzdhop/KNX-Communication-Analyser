#include <Windows.h>
#include <iostream>
#include "DriverCore.h"

int main()
{
	const unsigned int buffer_size(10);
	DWORD Buffer[buffer_size] = { 0 };

	//load dllinto addr space of client proc
	HMODULE hDLL = LoadLibraryExW(L"DriverCore.dll", nullptr, 0);
	if (!hDLL) {
		std::cout << "Cannot load DLL !";
		return ERROR;
	}

	//Resolve Objects Addr
	using GreetingType = SerialPort * (__cdecl*)(); //type def ptr to func w/ retType<void> argv/c<void>
	GreetingType pSerialPort = reinterpret_cast<GreetingType>(GetProcAddress(hDLL, "CreateSerialPort"));
	if (!pSerialPort) {
		std::cout << "Cannot load Function !";
		return ERROR;
	}
	SerialPort* CSerialPort = pSerialPort();

	CSerialPort->HelloWorld();
	std::cout << "\n\n";
	
	CSerialPort->readSerialPort(&Buffer, &buffer_size);

	return 0;
}