// DriverCore.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "DriverCore.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <clocale>
#include <locale>

#define BAUDRATE 9600
#define MAX_KEY_LENGTH 255
#define MAX_VALUE_NAME 16383

extern "C" __declspec(dllexport) SerialPort * __cdecl CreateSerialPort(const char* portName)
{
	return new SerialPort(portName);
}


SerialPort::SerialPort(const char* portName = "NOCOM") 
{
	this->_errors = 0;
	this->_status = { 0 };
	this->_connState = FALSE;

	//debug cond
	if (std::strcmp(portName, "NOCOM")) this->_portName = (LPCSTR)this->_autoSelectPort(this->_SerialList()).c_str();
	else this->_portName = (LPCSTR)portName;

	//Init I/O stream windows handler
	this->_streamHandle = CreateFileA(this->_portName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (this->_streamHandle == INVALID_HANDLE_VALUE) {
        if (GetLastError() == ERROR_FILE_NOT_FOUND) {
            std::cout << "ERROR: Handle was not attached. Reason: " << portName << " not available\n";
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
			std::cout << "ALERT: could not set Serial port parameters\n" ;
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

std::string SerialPort::_autoSelectPort(std::vector<std::string> serialList)
{

	return "COM6";
}
std::vector<std::string> SerialPort::_SerialList()
{
	std::vector<std::wstring> serialList;
	std::vector<std::string> strSerialList;
	std::string COMName("COM"), queryName(COMName);
	TCHAR bufferTragetPath[512];
	std::string tmp;
	int path_size(0);

	//teste each COM name to get the one used by the system
	for (int i(0); i < 255; i++)
	{
		queryName = COMName + std::to_string(i);
		std::cout << "testing  " << queryName << std::endl;
		path_size = QueryDosDeviceW((WCHAR*)&queryName, (LPWSTR)bufferTragetPath, 512);//Query the path of the COMName
		if (path_size != 0) {
			std::cout << "pushing..." << std::endl;
			serialList.push_back(bufferTragetPath);
		}		
	}
	//converting path to str and return std::vector<std::string>
	for (unsigned int i(0); i < serialList.size(); i++) {
		tmp = this->_w_to_s(serialList.back());
		serialList.pop_back();
		strSerialList.push_back(tmp);
	}
	return strSerialList;

	/*
	HKEY regValue;

	//opening a Key module
	LSTATUS HKEYStream = RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SYSTEM\\CurrentControlSet\\Enum\\USB\\VID_067B&PID_2303", 0, KEY_ENUMERATE_SUB_KEYS, &regValue);
	
	//----------------Listing subRegistery------------------
	DWORD i, retCode;
	TCHAR achValue[MAX_VALUE_NAME];
	DWORD cchValue = MAX_VALUE_NAME;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, NULL, 0, KEY_READ, &regValue) == ERROR_SUCCESS)
	{
		//QueryKey(hTestKey);
		TCHAR    achKey[MAX_KEY_LENGTH];   // buffer for subkey name
		DWORD    cbName;                   // size of name string 
		TCHAR    achClass[MAX_PATH] = TEXT("");  // buffer for class name 
		DWORD    cchClassName = MAX_PATH;  // size of class string 
		DWORD    cSubKeys = 0;               // number of subkeys 
		DWORD    cbMaxSubKey;              // longest subkey size 
		DWORD    cchMaxClass;              // longest class string 
		DWORD    cValues;              // number of values for key 
		DWORD    cchMaxValue;          // longest value name 
		DWORD    cbMaxValueData;       // longest value data 
		DWORD    cbSecurityDescriptor; // size of security descriptor 
		FILETIME ftLastWriteTime;      // last write time 

		retCode = RegQueryInfoKey(hTestKey, 
								achClass, 
								&cchClassName,
								NULL, 
								&cSubKeys, 
								&cbMaxSubKey,
								&cchMaxClass,
								&cValues,
								&cchMaxValue,
								&cbMaxValueData,
								&cbSecurityDescriptor,
								&ftLastWriteTime);
	*/
}


void SerialPort::HelloWorld()
{
    std::cout << "Hello World !\n";
}
