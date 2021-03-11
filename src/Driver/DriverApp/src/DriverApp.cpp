#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>
#include <string>
#include <vector>
#include "..\..\DriverCore\src\DriverCore.h"

int main()
{
	std::cout << "Initialising Serial Port";

	SerialPort* CSerialPort = _InitSerialPort();
	
	if (CSerialPort == nullptr) std::cout << std::endl << "Errorno :" << GetLastError() << std::endl;
	std::cout << "Binding and reading port: " << CSerialPort->getPortName() << std::endl;
	while(1) std::cout << readSerialBuffer(CSerialPort, 20);


	return 0;
}