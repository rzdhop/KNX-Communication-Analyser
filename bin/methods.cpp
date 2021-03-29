//FOR TESTS ONLY. DO NOT INCLUDE IN THE FINAL PROJECT ON GITHUB, THANKS
#include <iostream>
#include <string>
#include <bitset>
#include <cstring>
//#include "convert_methods.hpp"

int hex_to_dec(char num[]) {
   int len = strlen(num);
   int base = 1;
   int temp = 0;
   for (int i=len-1; i>=0; i--) {
      if (num[i]>='0' && num[i]<='9') {
         temp += (num[i] - 48)*base;
         base = base * 16;
      }
      else if (num[i]>='A' && num[i]<='F') {
         temp += (num[i] - 55)*base;
         base = base*16;
      } //convertir les lettres en nombres décimaux 
   }
   return temp;
}

int ch_to_binary(int received_number)
{
    std::string binary = std::bitset<8>(received_number).to_string(); //convertit la chaîne de caractères en binaire
    std::cout<<binary<<"\n";

    unsigned long decimal = std::bitset<8>(binary).to_ulong();
    std::cout<<decimal<<"\n";
    return 0;
}

int decode_hed(std::string receivedKNXFrame)
{
    std::string temp0;
    int temp1;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(0, 3);
    char num[] = "3F456A";
    temp1 = hex_to_dec(num);//<<std::endl;

    temp1 = ch_to_binary(temp1);
    
    return temp1;
    
}

std::string sourceAdress(std::string receivedKNXFrame)
{
    std::string temp0;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(0, 8); //old: 16
    
    return temp0;
    
}

std::string destinationAdress(std::string receivedKNXFrame)
{
    std::string temp0;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(24, 8);//old: 16
    
    return temp0;
    
}

std::string typeCast(std::string receivedKNXFrame)
{
    std::string temp0;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(40, 1);
    
    return temp0;
    
}

std::string variableCR(std::string receivedKNXFrame)
{
    std::string temp0;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(41, 3);
    
    return temp0;
    
}

std::string longFrame(std::string receivedKNXFrame)
{
    std::string temp0;

    //std::string pi = std::to_string(receivedKNXFrame);
    temp0 = receivedKNXFrame.substr(44, 3);
    
    return temp0;
    
}

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

int main()
{
    std::string temp;
    std::string vbAdress("bc1197bbdb71070770a0e79c1117bb7b9ce1008137ff9c11c9672f73b8000bddfc9c17b8d96d71e107b8d0c7"); //WARNING: La trame est trop courte. Il faut d'adapter!

    //other string to test: "BC120A3303E100810BCC"

    std::cout << "bonjour\n";
    std::cout << "\n";

    //int var_controlByte = controlByte(vbAdress);
    //std::cout << "The source adress is : " << var_controlByte << std::endl;



    //////////////////////////////

    char num[] = "28";
    std::cout << "Header ---" << decode_hed(num) << std::endl;
   

    temp = sourceAdress(vbAdress);
    std::cout << "The source adress is : " << temp << std::endl;

    temp = destinationAdress(vbAdress);
    std::cout << "The destination adress is : " << temp << std::endl;

    temp = typeCast(vbAdress);
    std::cout << "The type of cast is : " << temp << std::endl;

    temp = variableCR(vbAdress);
    std::cout << "The CR is : " << temp << std::endl;

    temp = longFrame(vbAdress);
    std::cout << "The long of the frame is : " << temp << std::endl;

}