/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/

#include <vector>
#include <iostream>
#include <cmath>

std::vector<int> PrimeArray;
std::vector<int>::iterator PrimeArrayIterator;

long int SumOfPrimes(std::vector<int> PrimeArray)
{
    std::vector<int>::iterator PrimeArrayIterator;
    long int sum = 0;

    for(PrimeArrayIterator = PrimeArray.begin(); PrimeArrayIterator != PrimeArray.end(); ++PrimeArrayIterator)
    {
        sum += *PrimeArrayIterator;
    }

    return sum;
}

bool CheckANumber(int Number)
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

    for(int i = 2; i <= 2000000; ++i)
    {
        if( CheckANumber(i) ) PrimeArray.push_back(i);
    }

    std::cout << "Sum: " << SumOfPrimes(PrimeArray) << std::endl;

    return 0;
}

