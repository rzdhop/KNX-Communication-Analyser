#include <iostream>
#include <string>
#include <bitset>
#include <cstring>
#include "decode.hpp"
#include "convertmethods.hpp"

/* 

std::string destinationAdress(std::string receivedKNXFrame)
{
    std::string temp0;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(6, 4);//old: 16
    
    return temp0;
    
}

/* std::string variableCR(std::string receivedKNXFrame)
{
    std::string temp0;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(41, 3);
    
    return temp0;
    
} */

/*

int controlByte(std::string receivedKNXFrame)
{
    std::string temp0;

    temp0 = receivedKNXFrame.substr(0, 2);

    

    //int mybit_int = (int)(temp0.to_ulong()); //Binary conversion
    //std::string binary = std::bitset<8>(temp0).to_string();
    //int temp1 = stoi(temp0);

    std::string s = "0xA";
    //std::stringstream ss;
    //ss << std::hex << s;
    unsigned n;
    //ss >> n;
    std::bitset<32> b(n);
    // outputs "00000000000000000000000000001010"
    std::cout << b.to_string() << std::endl;

    //return temp0;
    
}

bool calcpriority(std::string receivedKNXFrameBinary)


char extPriority(std::string receivedKNXFrameBinary)
{
    std::string temp_priority;

    temp_priority = receivedKNXFrameBinary.substr(4, 2);

    unsigned int temp_priorityDEC = std::stoi (temp_priority);

    switch(temp_priorityDEC)
    {
        case 00 : return 'S'; //SYSTEM;
        case 10 : return 'A'; // ALARM
        case 01 : return 'H'; // HIGH
        case 11 : return 'L'; // LOW
    }
}

std::string dataKNXNetworks(std::string receivedKNXFrame)
{
    std::string temp0;
    int temp1;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(10, 2);

    char* char_arr;
    std::string str_obj(temp0);
    char_arr = &str_obj[0]; //Convert string into char.

    temp1 = hex_to_dec(char_arr);
    temp0 = ch_to_binary(temp1);
    //temp1 = stoi(temp0);

    return temp0;

}

std::string hexData(std::string receivedKNXFrame, unsigned int lengthOfData)
{
    std::string temp0;

    temp0 = receivedKNXFrame.substr(12, lengthOfData);

    return temp0;

}

bool isGroupAddress(std::string receivedKNXFrameBinary)
{
    std::string temp0;

    temp0 = receivedKNXFrameBinary.substr(0, 1);
    bool tempGroupAddress = std::stoi (temp0);

    if (tempGroupAddress == 0)
    {
        return false;
    }

    if (tempGroupAddress == 1)
    {
        return true;
    }

}

unsigned int TTL(std::string receivedKNXFrameBinary)
{
    std::string temp0;

    temp0 = receivedKNXFrameBinary.substr(1, 3);
    unsigned int tempTTL = std::stoi (temp0, 0, 2);

    return tempTTL;

}

std::string parity (std::string receivedKNXFrame, unsigned int receivedLongFrame)
{
    std::string temp0;

    temp0 = receivedKNXFrame.substr((12 + receivedLongFrame), 2);

    return temp0;
}

unsigned int longFrame (std::string receivedKNXFrameBinary)
{
    std::string temp0;

    temp0 = receivedKNXFrameBinary.substr(4, 4);
    unsigned int tempLongFrame = std::stoi (temp0, 0, 2);

    tempLongFrame *= 2;

    return tempLongFrame; 
}

void test()
{
    std::cout << "test" << std::endl;
};



/*

class log;
{
public:
    void sys(std::string wlog);
};

void log::sys(std::string wlog):
{
    freopen ("myfile.txt","w",stdout);
    printf (wlog);
    fclose (stdout);
}

*/