//FOR TESTS ONLY. DO NOT INCLUDE IN THE FINAL PROJECT ON GITHUB, THANKS
#include <iostream>
#include <string>

std::string sourceAdress(int receivedKNXFrame)
{
    std::string temp0;

    std::string pi = std::to_string(receivedKNXFrame);
    temp0 = pi.substr(0, 2);
    
    return temp0;
    
}

int main()
{
    long long int vbAdress(857457575757575856);

    std::cout << "bonjour\n";
    std::cout << "\n";

    std::string temp;
    temp = sourceAdress(vbAdress);
    std::cout << "The source adress is : " << temp << std::endl;

}