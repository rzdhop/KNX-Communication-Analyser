//WARNING DO NOT PUSH ON GITHUB THIS IS A TEST FOR CUTTING STRINGS THANKS YOU!!!

#include <iostream> 
using namespace std; 
  
int main() 
{ 
    // Take any string 
    string s1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
  
    // Copy three characters of s1 (starting  
    // from position 1) 
    string r = s1.substr(10, 7); 
  
    // prints the result 
    cout << "String is: " << r; 
  
    return 0; 
} 