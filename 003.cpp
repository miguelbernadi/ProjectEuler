/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <iostream>
#include <vector>
#include <cmath>

std::vector<unsigned int> primes;
std::vector<unsigned int>::iterator iter;

std::vector<unsigned int> factors;
std::vector<unsigned int>::iterator iter2;

bool is_prime(unsigned int& factor)
{
    for(iter = primes.begin(); iter < primes.end(); iter++)
    {
        if(factor % *iter == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
// We find all factors for the number.
    for(unsigned int i = 3; i < sqrt(600851475143); i += 2)
    {
        if(600851475143 % i == 0)
        {
            factors.push_back(i);
        }
    }

// Now we check all prime numbers applicable to any of the factors.
    if(primes.size() == 0)
    {
        primes.push_back(2);
    }

    iter2 = factors.end();
    --iter2;

    for(unsigned int i = 3; i < sqrt( *iter2 ); ++i)
    {
        if ( is_prime(i) )
        {
            primes.push_back(i);
        }
    }

// Now we check for each factor to see if it is prime or not.
    for(iter2 = factors.begin(); iter2 != factors.end(); ++iter2)
    {
        if( is_prime(*iter2) )
        {
            std::cout << *iter2 << std::endl;
        }
    }
    return 0;
}
