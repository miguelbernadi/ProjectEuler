/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10001st prime number?
*/

#include <vector>
#include <iostream>
#include <cmath>

std::vector<long int> PrimeArray;
std::vector<long int>::iterator PrimeArrayIterator;

bool CheckANumber(long int Number)
{
    for(PrimeArrayIterator = PrimeArray.begin(); PrimeArrayIterator != PrimeArray.end(); ++PrimeArrayIterator)
    {
        if(Number % *PrimeArrayIterator == 0)
        {
            return false;
        }
        if( sqrt(Number) <= *PrimeArrayIterator )
        {
            return true;
        }
    }
    return true;
}

int main()
{
    PrimeArray.push_back(2);

    for(long int i = 2; ; ++i)
    {
        if( CheckANumber(i) ) PrimeArray.push_back(i);
        if(PrimeArray.size() == 10001)
        {
            std::cout << PrimeArray.back() << "\n";
            return 0;
        }
    }

    return 0;
}
