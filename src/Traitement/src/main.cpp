#include <iostream>
#include "argh.h"
#include "convertmethods.hpp"
#include "decode.hpp"
#include <string>
#include <bitset>
#include <cstring>
#include <sstream>
#include "logs.hpp"

int main(int,char* argv[])
{
    argh::parser cmdl(argv);

        if (cmdl[{ "-ad", "--autodetect" }])
    {
        std::cout << "Welcome to KNX Communications Analyser. Autodetecting COM ports.. It can takes about 1 minute.\n";
        std::cout << "The following COM ports are been found : " << "COM4" << std::endl;
        std::cout << std::endl;
        //Call of the driverapp.exe created by rdzhop AND select the 1st port (unsure)

        //here comes the link to the function who cut the frames
    }

    if (cmdl[{ "-h", "--help" }])
    {
        std::cout << "Welcome to KNX Communications Analyser. This program is designed for Windows only." << std::endl;
        std::cout << "For now, this program is in COMMAND LINE ONLY." << std::endl;
        std::cout << "By default, the program is autodetecting ports on your computer. You also can specify one particular port by adding -p at the execution." << std::endl;
        std::cout << std::endl;
        //here comes the different arguments (-h; -p; -ad)
        std::cout << "MIT License - rzdhop, VictorFS78" << std::endl;
        return EXIT_SUCCESS;
    }

    if (cmdl[{ "-p", "--manualport" }])
    {
        std::cout << "\n***WARNING*** You're about to specify one specific port and override autodetection.\n --------> Are you sure about that? Please press Y : " << std::endl;
        char specificPortConfirmation;
        std::cin >> specificPortConfirmation;

        if (specificPortConfirmation == 'Y')
        {
            std::cout << "THE FOLLOWING COM PORTS ARE BEEN FOUND:" << std::endl;
            //Call of the driverapp.exe created by rdzop
            std::cout << "If you don't see the port you want to use, or see no ports, click on the Cortana bar, then 'Device Manager', and then, click on 'COM Ports' to see if your serial ports are been detected by your computer." << std::endl;

            std::cout << "What port do you want to use?" << std::endl;

        }

        if (specificPortConfirmation != 'Y')
        {
            std::cout << "Great. Don't worry. The program will shutdown, and you can reload. By default, you should use -ad." << std::endl;
            return EXIT_SUCCESS;
        }

    }

    std::string vbAdress("BC120A3303E100810BCC"); //DEFAULT FRAME IF NOTHING IS SPECIFIED

    if (cmdl[{ "-f", "--frame" }])
    {
        std::cout << "Manual frame mode. Please write your frame here and press ENTER : " << std::endl;
        std::cin >> vbAdress;
        std::cout << std::endl << std::endl;

    }

    if (!cmdl[{ "-f", "--frame", "-p", "--manualport", "-h", "--help", "-ad", "--autodetect"  }])
        {
            std::cout << std::endl << "WARN: Sorry, you dosen't specified one argument, or the argument you entered is incorrect." << std::endl;
            std::cout << "      Please try again. If you need help please specify the argument '-h' or '--help'" << std::endl;
            std::cout << "      If needed, you can read the documentation at https://github.com/rzdhop/KNX-Communication-Analyser" << std::endl << std::endl;
            return EXIT_SUCCESS;
        }



    Decode adresse1;
    Logs adresse2;
    std::ostringstream writeToLogs;

    adresse1.receivedKNXFrame = vbAdress;

    std::cout << "The used frame is : " << adresse1.receivedKNXFrame << std::endl;
    writeToLogs << "The used frame is : " << adresse1.receivedKNXFrame << std::endl;

    std::string tempHeader = adresse1.decode_hed();
    std::cout << "The header of this KNX frame is : " << tempHeader << std::endl;
    writeToLogs<< "The header of this KNX frame is : " << tempHeader << std::endl;


    bool typeFrame = adresse1.calcpriority();
        if (typeFrame == true)
            {
                 std::cout << "This frame is a REPETITION";
                 writeToLogs << "This frame is a REPETITION";
            }

        if (typeFrame == false)
            {
                 std::cout << "This frame is a NORMAL frame";
                 writeToLogs << "This frame is a NORMAL frame";
            }


    std::string tempPriorityFrame = adresse1.extPriority();

    std::cout << " and the priority of emission was " << tempPriorityFrame << std::endl;
    writeToLogs << " and the priority of emission was " << tempPriorityFrame << std::endl;



    std::string tempSourceAdress = adresse1.sourceAdress();
    std::cout << "The source adress is : " << tempSourceAdress << std::endl;
    writeToLogs << "The source adress is : " << tempSourceAdress << std::endl;

    std::string tempDestinationAdress = adresse1.destinationAdress();
    std::cout << "The destination adress is : " << tempDestinationAdress << std::endl; //jusqu'à là ok, ne pas toucher
    writeToLogs << "The destination adress is : " << tempDestinationAdress << std::endl;

std::string binDataKNXNetworks = adresse1.dataKNXNetworks();
    std::cout << "The binary of the network KNX is : " << binDataKNXNetworks << std::endl;
    writeToLogs << "The binary of the network KNX is : " << binDataKNXNetworks << std::endl;
   
    unsigned int tempLongFrame = adresse1.longFrame();
    std::cout << "The length of the frame is : " << tempLongFrame << std::endl;
    writeToLogs << "The length of the frame is : " << tempLongFrame << std::endl;

    bool tempIsGroupAdress = adresse1.isGroupAddress();
        if (tempIsGroupAdress == true)
            {
                 std::cout << "This frame is part of a group" << std::endl;
                 writeToLogs << "This frame is part of a group" << std::endl;
            }

        if (tempIsGroupAdress == false)
            {
                 std::cout << "This frame isn't part of a group" << std::endl;
                 writeToLogs << "This frame isn't part of a group" << std::endl;
            }

    unsigned int tempTTL = adresse1.TTL();
    std::cout << "The TTL is :" << tempTTL << std::endl; //Il faut mettre le bittojump
    writeToLogs << "The TTL is :" << tempTTL << std::endl;

    std::string tempHexData = adresse1.hexData();
    std::cout << "The datas extracted from the frame are : " << tempHexData << std::endl;
    writeToLogs << "The datas extracted from the frame are : " << tempHexData << std::endl;

    std::string tempParity = adresse1.parity();
    std::cout << "Finally, the parity byte are : " << tempParity << std::endl;
    writeToLogs << "Finally, the parity byte are : " << tempParity << std::endl;

    unsigned int tempVerifyAck = adresse1.verifyAck();
        if (tempVerifyAck == 0)
            {
                 std::cout << "This frame was sent with an INCORRECT reception" << std::endl;
                 writeToLogs << "This frame was sent with an INCORRECT reception" << std::endl;
            }

        if (tempVerifyAck == 1)
            {
                 std::cout << "This frame was sent, but the bus was BUSY! Warning.." << std::endl;
                 writeToLogs << "This frame was sent, but the bus was BUSY! Warning.." << std::endl;
            }
        if (tempVerifyAck == 2)
            {
                 std::cout << "This frame was sent, and the reception was correct." << std::endl;
                 writeToLogs << "This frame was sent, and the reception was correct." << std::endl;
            }

        else {std::cout <<"WARN: UNDEFINED ERROR!" << std::endl;}

    std::cout << std::endl;
    std::cout << "Writing logs...";

    adresse2.tempStr = writeToLogs.str();

    adresse2.writingLogs();

    return EXIT_SUCCESS;
}
