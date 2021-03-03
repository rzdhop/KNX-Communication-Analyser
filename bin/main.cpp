//MARCH 3RD 2021 --  THIS PROGRAM ISN'T FONCTIONNAL FOR NOW. COMMAND LINE ONLY.

#include <iostream>
#include "argh.h"

int main(int, char* argv[])
{
    argh::parser cmdl(argv);

    if (cmdl[{ "-h", "--help" }])
    {
        std::cout << "Welcome to KNX Communications Analyser. This program is designed for Windows only.\n";
        std::cout << "For now, this program is in COMMAND LINE ONLY.\n";
        std::cout << "By default, the program is autodetecting ports on your computer. You also can specify one particular port by adding -p at the execution.\n";
        std::cout << "\n";
    }

    if (cmdl[{ "-p", "--test" }])
    {
        std::cout << "\n***WARNING*** You're about to specify one specific port and override autodetection.\n --------> Are you sure about that? Please press Y : ";
        char specificPortConfirmation;
        std::cin >> specificPortConfirmation;

        if (specificPortConfirmation == 'Y')
	    {
            std::cout << "THE FOLLOWING COM PORTS ARE BEEN FOUND:\n";
            //rzdhop work folder go here
            std::cout << "If you don't see the port you want to use, or see no ports, click on the Cortana bar, then 'Device Manager', and then, click on 'COM Ports' to see if your serial ports are been detected by your computer.\n";

            std::cout << "What port do you want to use?\n";
            //AFTER -- DRAFT ON VICTOR'S PC BUT STILL NOT WORKING.

            //here comes the link to the function who cut the frames
        }

        if (specificPortConfirmation != 'Y')
        {
            std::cout << "Great. Don't worry. The program will shutdown, and you can reload. By default, you should use -ad \n";
        }

        
    if (cmdl[{ "-ad", "--autodetect" }])
    {
        std::cout << "Welcome to KNX Communications Analyser. Autodetecting COM ports.. It can takes about 1 minute.\n";
        std::cout << "The following COM ports are been found : " << "x" << std::endl;
        std::cout << "\n";

        //here comes the link to the function who cut the frames
    }

    }

    return EXIT_SUCCESS;
}

