#pragma once

#include <iostream>
#include <string>
#include <bitset>
#include <cstring>
#include "convertmethods.hpp"
#include <fstream>
#include <ctime>

class Decode
{
public:

    std::string receivedKNXFrame;
    std::string receivedKNXFrameBinary;
    unsigned int lengthOfData;

    //Méthodes:
    std::string decode_hed()
    {
        std::string temp0;
        int temp1;

        //std::string pi = std::to_string(receivedKNXFrame);
        temp0 = receivedKNXFrame.substr(0, 2);

        char* char_arr;
        std::string str_obj(temp0);
        char_arr = &str_obj[0]; //Convert string into char.

        temp1 = hex_to_dec(char_arr);
        temp0 = ch_to_binary(temp1);
    
        return temp0;
    }

    std::string sourceAdress()
    {
            std::string temp0;

            //std::string pi = std::to_string(receivedKNXFrame);
            temp0 = receivedKNXFrame.substr(2, 4); //old: 16

            return temp0;
    }

    std::string dataKNXNetworks()
    {
        std::string temp0;
        int temp1;

        temp0 = receivedKNXFrame.substr(10, 2);

        char* char_arr;
        std::string str_obj(temp0);
        char_arr = &str_obj[0]; //Convert string into char.

        temp1 = hex_to_dec(char_arr);
        temp0 = ch_to_binary(temp1);
        //temp1 = stoi(temp0);

        Decode::receivedKNXFrameBinary = temp0;

        return temp0;

    }

    bool calcpriority()
        {
            //With the frame received by decode_hed

            std::string temp_priority;

            temp_priority = receivedKNXFrameBinary.substr(2, 1);

            if (temp_priority == "0")
            {
                return true;
            }

            if (temp_priority == "1")
            {
                return false;
            }

        }

    std::string extPriority()
    {
        std::string temp_priority;

        temp_priority = receivedKNXFrameBinary.substr(4, 2);

        unsigned int temp_priorityDEC = std::stoi (temp_priority);

        switch(temp_priorityDEC)
        {
            case 00 : return "SYSTEM"; 
            case 10 : return "ALARM";
            case 01 : return "HIGH";
            case 11 : return "LOW";
        }
    }

    std::string destinationAdress()
    {
        std::string temp0;

        temp0 = receivedKNXFrame.substr(6, 4);

        return temp0;
    }

    unsigned int longFrame()
    {
        std::string temp0;

        temp0 = receivedKNXFrameBinary.substr(4, 4);
        unsigned int tempLongFrame = std::stoi (temp0, 0, 2);

        tempLongFrame *= 2;

        Decode::lengthOfData = tempLongFrame;

        return tempLongFrame; 
    }

     bool isGroupAddress()
     {
        std::string temp0;

        temp0 = receivedKNXFrameBinary.substr(0, 1);
        bool tempGroupAddress = std::stoi (temp0);

        if (tempGroupAddress == 0)
        {
            return 0;
        }

        if (tempGroupAddress == 1)
        {
            return 1;
        }

    }

    unsigned int TTL()
    {
        std::string temp0;

        temp0 = receivedKNXFrameBinary.substr(1, 3);
        unsigned int tempTTL = std::stoi (temp0, 0, 2);

        return tempTTL;
    }

    std::string hexData()
    {
        std::string temp0;

        temp0 = receivedKNXFrame.substr(12, (lengthOfData * 2));

        return temp0;
    }

    std::string parity()
    {
        std::string temp0;

        temp0 = receivedKNXFrame.substr((12 + lengthOfData), 2);

        return temp0;
    }

    int controlByte()
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
        //-------UNSURE--------
    }


};


class Logs
{
    public:
    std::string tempStr;
    void test()
    {
        std::string const filename("logs.txt");
        std::ofstream writeLogs(filename.c_str());

        if(writeLogs)    
            {
                writeLogs << "KNX Communication Analyzer -- ";
                std::time_t result = std::time(nullptr);
                writeLogs << std::asctime(std::localtime(&result)) << std::endl;

                writeLogs << tempStr;

                writeLogs << std::endl << "-------------END-" << std::endl;
                std::cout << "OK" << std::endl;
            }
        else
            {
                std::cout << "WARNING! Error: unable to create or open logs.txt" << std::endl;
            }
    }
};