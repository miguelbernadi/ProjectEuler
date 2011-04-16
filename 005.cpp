/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <iostream>

bool isdivisible(int number)
{
    bool divisible = true;
    for(int factor = 1; factor <= 20; factor++)
    {
        if(number % factor == 0)
        {
            divisible = true;
        }
        else
        {
            divisible = false;
            return divisible;
        }
    }
    return divisible;
}

int main()
{
    int result = 0;
    for(int i = 1;;i++)
    {
        if( isdivisible(i) )
        {
            result = i;
            break;
        }
    }
    std::cout << result << std::endl;
    return 0;
}
