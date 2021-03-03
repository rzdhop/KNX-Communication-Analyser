#pragma once

class SerialPort
{
private:
	bool connected = 0;
public:
	SerialPort();
	virtual void HelloWorld();
	virtual bool isConnected();
	virtual int readSerialPort(char* buffer, unsigned int buf_size);
	virtual bool writeSerialPort(char* buffer, unsigned int buf_size);
};