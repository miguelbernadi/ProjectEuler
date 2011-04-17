/*
The following iterative sequence is defined for the set of positive integers:

n  n/2 (n is even)
n  3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13  40  20  10  5  16  8  4  2  1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>

int sequence_odd(int n)
{
    return 3 * n + 1;
}

int sequence_even(int n)
{
    return n / 2;
}

int sequence_long(int seed)
{
    int counter = 0;
    while (seed > 1)
    {
        if( seed % 2 == 0)
        {
            seed = sequence_even(seed);
        }
        else
        {
            seed = sequence_odd(seed);
        }
        ++counter;
    }
    return counter;
}

struct pair
{
  int seed, seqlong;
};

int main()
{
    int max_long = 0;
    int dummy;
    pair pair;
    for(int i = 1; i < 1000000; ++i)
    {
        dummy = sequence_long(i);
        if(max_long < dummy)
        {
            max_long = dummy;
            pair.seed = i;
            pair.seqlong = dummy;
        }
    }
    std::cout << pair.seed << std::endl;
    return 0;
}
