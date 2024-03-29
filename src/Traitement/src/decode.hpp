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
    std::string receivedKNXFrameBinaryHeader;
    unsigned int lengthOfData;

    //Méthodes:
    std::string decode_hed()
    {
        std::string temp0;
        int temp1;

        temp0 = receivedKNXFrame.substr(0, 2);

        char* char_arr;
        std::string str_obj(temp0);
        char_arr = &str_obj[0]; //Convert string into char.

        temp1 = hex_to_dec(char_arr);
        temp0 = ch_to_binary(temp1);

        Decode::receivedKNXFrameBinaryHeader = temp0;
    
        return temp0;
    }

    std::string sourceAdress()
    {
            std::string temp0;

            temp0 = receivedKNXFrame.substr(2, 4); //old: 16

            return temp0;
    }

    std::string dataKNXNetworks()
    {
        std::string temp2;
        int temp3;

        temp2 = receivedKNXFrame.substr(10, 2);

        char* char_arr;
        std::string str_obj(temp2);
        char_arr = &str_obj[0]; //Convert string into char.

        temp3 = hex_to_dec(char_arr);
        temp2 = ch_to_binary(temp3);
        //temp1 = stoi(temp0);

        Decode::receivedKNXFrameBinary = temp2;

        return temp2;

    }

    bool calcpriority()
        {
            //With the frame received by decode_hed

            std::string temp_priority;

            temp_priority = receivedKNXFrameBinaryHeader.substr(2, 1);

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

        temp_priority = receivedKNXFrameBinaryHeader.substr(4, 2);

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

        std::string s = "0xA";

        unsigned n;
        std::bitset<32> b(n);
        std::cout << b.to_string() << std::endl;

    }

    unsigned int verifyAck()
    {
        std::string temp0;

        temp0 = receivedKNXFrame.substr((14 + (lengthOfData + 1)), 2);
           //std::cout << "verifyAck" << temp0 << std::endl;
            if (temp0 == "0C")
            {
                return 0;
            }

            if (temp0 == "C0")
            {
                return 1;
            }

            if (temp0 == "CC")
            {
                return 2;
            }

            else
            {
                unsigned int temp_anotherACK = std::stoi (temp0);
                return temp_anotherACK;
            }
    }

};
