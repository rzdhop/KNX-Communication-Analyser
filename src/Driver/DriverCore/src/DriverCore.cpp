#define WIN32_LEAN_AND_MEAN
#define BAUDRATE 9600
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

#include "DriverCore.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <clocale>
#include <locale>

extern "C" __declspec(dllexport) SerialPort * __cdecl CreateSerialPort()
{
	return new SerialPort();
}

SerialPort::SerialPort()
{
	this->_errors = 0;
	this->_status = { 0 };
	this->_connState = FALSE;

	//debug cond
	auto tmp = this->_autoSelectPort(this->_SerialList());
	this->_portName = tmp.c_str();

	std::cout << "Port name: " << this->_portName << std::endl;
	//Init I/O stream windows handler
	this->_streamHandle = CreateFileA((LPCSTR)this->_portName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (this->_streamHandle == INVALID_HANDLE_VALUE) {
		if (GetLastError() == ERROR_FILE_NOT_FOUND) {
			std::cout << "ERROR: Handle was not attached. Reason: " << this->_portName << " not available\n";
		}
		else { printf("Undefined Error ! %d \n", GetLastError()); return; }
	}

	//Declare pointer to LPDCB struct (serialCOM parameters)
	DCB dcbSerialParameters = { 0 };

	if (!GetCommState(this->_streamHandle, &dcbSerialParameters)) {
		std::cout << "Failed to retreive current serial parameter ! \n";
		return;
	}
	else {
		//Define dcbSerialParameters struct's parameter
		dcbSerialParameters.BaudRate = CBR_9600;
		dcbSerialParameters.ByteSize = 8;
		dcbSerialParameters.StopBits = ONESTOPBIT;
		dcbSerialParameters.Parity = NOPARITY;
		dcbSerialParameters.fDtrControl = DTR_CONTROL_ENABLE;

		if (!SetCommState(this->_streamHandle, &dcbSerialParameters)) {
			std::cout << "ALERT: could not set Serial port parameters\n";
			return;
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
	std::cout << "closing port";
	if (this->_connState) CloseHandle(this->_streamHandle);
	else std::cout << "There is no connection to Terminate \n";
	return;
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
std::string SerialPort::_autoSelectPort(std::vector<std::string> serialList)
{

	return "";
}
std::vector<std::string> SerialPort::_SerialList()
{
	std::vector<std::string> serialList;
	std::string COMName("COM"), queryName("");
	char bufferTragetPath[5000];
	std::string tmp;
	DWORD path_size(0);

	//test each COM name to get the one used by the system and get his description name
	for (int i(0); i < 255; i++)
	{
		queryName = COMName + std::to_string(i);

		//Query the path of the COMName
		path_size = QueryDosDeviceA(queryName.c_str(), bufferTragetPath, 5000);
		std::cout << std::endl << "Path for " << queryName << ":" << path_size << "   " << queryName;
		if (path_size != 0) {
			std::cout << "pushing..." << queryName << " on " << bufferTragetPath << std::endl;
			serialList.push_back(tmp);
		}
	}
	return serialList;
}
//make a tamplate
std::string SerialPort::_w_to_s(std::wstring WSTRING)
{
	std::setlocale(LC_ALL, "");
	const std::locale locale("");
	typedef std::codecvt<wchar_t, char, std::mbstate_t> converter_type;
	const converter_type& converter = std::use_facet<converter_type>(locale);
	std::vector<char> to(WSTRING.length() * converter.max_length());
	std::mbstate_t state;
	const wchar_t* from_next;
	char* to_next;
	const converter_type::result result = converter.out(state, WSTRING.data(), WSTRING.data() + WSTRING.length(), from_next, &to[0], (&to[0] + to.size()), to_next);
	if (result == converter_type::ok or result == converter_type::noconv) {
		const std::string s(&to[0], to_next);
		return s;
	}
	return "Error";
}
void SerialPort::HelloWorld()
{
	std::cout << "Hello World !\n";
}