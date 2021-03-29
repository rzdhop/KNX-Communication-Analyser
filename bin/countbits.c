#include <stdio.h>      
#include <math.h>
 
unsigned countBits(unsigned int number)
{      
      // log function in base 2 
      // take only integer part
      return (int)log2(number)+1;
}
 
// Driven program       
int main()
{
    unsigned int num = "bc1197bbdb71070770a0e79c1117bb7b9ce1008137ff9c11c9672f73b8000bddfc9c17b8d96d71e107b8d0c7";
    printf("%d\n", countBits(num));
    return 0;
} 