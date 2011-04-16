/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>

unsigned long int table[500] = { 0 };

bool check(unsigned long int i, unsigned long int j);
bool check3(unsigned long int i);
bool check5(unsigned long int i);

bool check(unsigned long int i, unsigned long int j)
{
   if(i % j == 0)
   {
       return true;
   }
   return false;
}

bool check3(unsigned long int i)
{
   return check(i,3);
}

bool check5(unsigned long int i)
{
   return check(i,5);
}

int main()
{
   unsigned int index = 0;
   for (unsigned long int i = 1; i < 1000; i++)
   {
      if( check3(i) )
      {
         table[index] = i;
         index++;
      }
      else
      {
         if( check5(i) )
         {
            table[index] = i;
            index++;
         }
     }
   }
   unsigned long int total = 0;
   for(unsigned int i = 0; i < index; i++)
   {
      std::cout << table[i] << std::endl;
      total += table[i];
      std::cout << "current total " << total << std::endl;
   }
   std::cout << total << std::endl;
   return 0;
}
