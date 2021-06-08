#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "..\..\DriverCore\src\DriverCore.h"

int main()
{
	std::cout << std::endl << "[+] Initialising Serial Port" << std::endl;

	SerialPort* CSerialPort = _InitSerialPort(R"(..\..\DriverCore\bin\DriverCore.dll)");

	if (CSerialPort == nullptr) std::cout << std::endl << "[-] Errorno :" << GetLastError() << std::endl;

	std::cout << "[+] Reading COM port :" << std::endl;
	while(1) std::cout << readSerialBuffer(CSerialPort, 1);

	return 0;
}