/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

//Forma totalmente diferente ( no calcular todos primos sino calcular factores )

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<unsigned int> primes;
vector<unsigned int>::iterator iter;

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
    if(primes.size() == 0)
    {
        primes.push_back(2);
    }
    for(unsigned int i = 3; i < sqrt(600851475143); i += 2)
    {
        if( is_prime(i) )
        {
            primes.push_back(i);
            if(600851475143 % i == 0)
            {
                cout << i << endl;
            }
        }
    }
    return 0;
}
