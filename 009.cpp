/*
A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <cmath>

int compute(int a, int b, int c)
{
    if( a + b + c == 1000 )
    {
        return a*b*c;
    }
    return 0;
}

bool checkPitagorean(int a, int b, int c)
{
    if(a < b)
    {
        if(b < c)
        {
            if( pow(a,2) + pow(b,2) == pow(c,2) )
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{

    for(int a = 0; a < 1000; ++a)
    {
        for(int b = 0; b < 1000; ++b)
        {
            for(int c = 0; c < 1000; ++c)
            {
                if( checkPitagorean(a, b, c) )
                {
                    int temp = compute(a, b, c);
                    if(temp != 0)
                    {
                        std::cout << temp << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}
