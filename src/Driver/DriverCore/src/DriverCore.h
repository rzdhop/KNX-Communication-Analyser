#pragma once
#include <Windows.h>
#include <vector>
#include <string>

class SerialPort
{
private:
	HANDLE _streamHandle;
	bool _connState;
	LPCSTR _portName;
	COMSTAT _status;
	DWORD _errors;
public:
	SerialPort(const char* portName);
	~SerialPort();

	virtual void _CloseConn();
	virtual void HelloWorld();
	virtual bool isConnected();
	virtual std::string SerialList();
	virtual int readSerialPort(char* buffer, unsigned int buf_size);
};