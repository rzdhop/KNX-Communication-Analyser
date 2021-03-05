#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <vector>
#include <string>

class SerialPort
{
private:
	HANDLE _streamHandle;
	bool _connState;
	const char* _portName;
	COMSTAT _status;
	DWORD _errors;
public:
	SerialPort();
	~SerialPort();

	virtual void _CloseConn();
	virtual void HelloWorld();
	virtual bool isConnected();
	virtual std::vector<std::string> _SerialList();
	virtual std::string _w_to_s(std::wstring WSTRING);
	virtual std::string _autoSelectPort(std::vector<std::string> serialList);
	virtual int readSerialPort(char* buffer, unsigned int buf_size);
};

