#pragma once

#include <iostream>
#include <string>
#include <bitset>
#include <cstring>
#include "convertmethods.hpp"
#include <fstream>
#include <ctime>

class Logs
{
    public:
    std::string tempStr;
    void writingLogs()
    {
        std::string const filename("logs.txt");
        std::ofstream writeLogs(filename.c_str());

        if(writeLogs)    
            {
                writeLogs << "KNX Communication Analyzer -- ";
                std::time_t result = std::time(nullptr);
                writeLogs << std::asctime(std::localtime(&result)) << std::endl;

                writeLogs << tempStr;

                writeLogs << std::endl << "-------------END-" << std::endl << std::endl;
                std::cout << "OK" << std::endl;
            }
        else
            {
                std::cout << std::endl << "WARNING! Error: unable to create or open logs.txt" << std::endl;
            }
    }
};