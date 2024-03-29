#include "convertmethods.hpp"
#include <iostream>
#include <string>
#include <bitset>
#include <cstring>

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

std::string ch_to_binary(int received_number)
{
   //std::cout<<"ENTREE"<<std::endl;
    std::string binary = std::bitset<8>(received_number).to_string(); //convertit la chaîne de caractères en binaire
    //std::cout<<"uuduhdeuheuh"<<binary<<"\n"; //for testing purposes only!!!!!

    //unsigned long decimal = std::bitset<8>(binary).to_ulong();
    //std::cout<<decimal<<"\n";
    return binary;
}