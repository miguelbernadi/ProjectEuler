/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> table;
unsigned int total = 0;

bool check(unsigned int i, unsigned int j)
{
   if(i % j == 0)
   {
       return true;
   }
   return false;
}

void totals(unsigned int i)
{
    total += i;
}

int main()
{
   for (unsigned int i = 1; i < 1000; i++)
   {
      if( check(i, 3) || check(i, 5) )
      {
         table.push_back(i);
      }
   }
   std::for_each(table.begin(), table.end(), totals);
   std::cout << total << std::endl;
   return 0;
}

