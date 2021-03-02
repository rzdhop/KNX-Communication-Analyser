// DriverCore.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "DriverCore.h"
#include <iostream>

extern "C" SerialPort* __cdecl CreateSerialPort()
{
    return new SerialPort();
}

SerialPort::SerialPort(){}
int SerialPort::readSerialPort(char* buffer, unsigned int buf_size) { return 0; }
bool SerialPort::writeSerialPort(char* buffer, unsigned int buf_size) { return 0; }
bool SerialPort::isConnected() { return 0; }

void SerialPort::HelloWorld() 
{ 
    std::cout << "Hello World !"; 
}


