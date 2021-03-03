// DriverCore.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "DriverCore.h"
#include <iostream>
#include <windows.h>
#include <string>

#define BAUDRATE 9600

extern "C" __declspec(dllexport) SerialPort * __cdecl CreateSerialPort(const char* portName)
{
	return new SerialPort(portName);
}


SerialPort::SerialPort(const char* portName) 
{
	this->_errors = 0;
	this->_status = { 0 };
	this->_portName = (LPCSTR) portName;
	this->_connState = FALSE;

	//Init I/O stream windows handler
	this->_streamHandle = CreateFileA(this->_portName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (this->_streamHandle == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            std::cout << "ERROR: Handle was not attached. Reason: " << portName << " not available\n";
        }
        else {printf("Undefined Error !");}
	} 

	//Declare pointer to LPDCB struct (serialCOM parameters)
	DCB dcbSerialParameters = { 0 };

	if (!GetCommState(this->_streamHandle, &dcbSerialParameters)) {
		std::cout << "Failed to retreive current serial parameter !";
	}
	else {
		//Define dcbSerialParameters struct's parameter
		dcbSerialParameters.BaudRate = CBR_9600;
		dcbSerialParameters.ByteSize = 8;
		dcbSerialParameters.StopBits = ONESTOPBIT;
		dcbSerialParameters.Parity = NOPARITY;
		dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

		if (!SetCommState(this->_streamHandle, &dcbSerialParameters)) {
			std::cout << "ALERT: could not set Serial port parameters\n" ;
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
		this->_connState;
		this->_CloseConn();
	}
}
void SerialPort::_CloseConn()
{
	if (this->_connState) CloseHandle(this->_streamHandle);
	else std::cout << "There is no connection to Terminate";
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
		}
		else toRead = this->_status.cbInQue;
	}

	//Read Bytes from serial
	if (ReadFile(this->_streamHandle, buffer, toRead, &bytesRead, NULL)) return bytesRead;

	return 0;
}

bool SerialPort::isConnected() 
{ 
	return this->_connState;
}

std::string SerialPort::SerialList()
{
	std::vector<std::wstring> serialList;
	std::string COMName("COM"), queryName(COMName);
	TCHAR bufferTragetPath[512];
	int path_size(0);

	for (int i(0); i < 255; i++)
	{
		queryName = COMName + std::to_string(i);
		path_size = QueryDosDeviceW((WCHAR*)&queryName, (LPWSTR)bufferTragetPath, 512);//Query the path of the COMName
		if (path_size != 0) {
			serialList.push_back(bufferTragetPath);
		}		
	}




	return "";
}



void SerialPort::HelloWorld()
{
    std::cout << "Hello World !";
}