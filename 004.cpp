/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

/*
The product of two 3-digit numbers is a number of 6 or less digits, 999x999 = 998001

1st approach) Create all 6-digit palindromes (abccba) and 5 digit palindromes (0abcba) and decompose in 3-digit products.
2nd approach) Generate all 3-digit numbers, multiply them and check for palindromes within.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Palindrome
{
  private:
    int palindrome[6];

  public:
    Palindrome(int a, int b, int c, int d, int e, int f)
    {
         palindrome[0] = a;
         palindrome[1] = b;
         palindrome[2] = c;
         palindrome[3] = d;
         palindrome[4] = e;
         palindrome[5] = f;
    }
    int toInt()
    {
       int intPal = 0;
       for(int i = 0; i < 6; ++i)
       {
           intPal += this->palindrome[i] * std::pow(10, i);
        }
        return intPal;
    }
};

std::vector<Palindrome*> Collection;

void registerPalindrome(int a, int b, int c, int d, int e, int f)
{
    Palindrome* mPalindrome = new Palindrome(a, b, c, d, e, f);
    Collection.push_back( mPalindrome );
}

void generatePalindromes()
{
    int a, b, c, d;
    for(int i = 0; i < 10; ++i)
    {
        a = i;
        for(int ii = 0; ii < 10; ++ii)
        {
            b = ii;
            for(int iii = 0; iii < 10; ++iii)
            {
                c = iii;
                if(a == 0)
                {
                    for(int iv = 0; iv < 10; ++iv)
                    {
                        d = iv;
                        registerPalindrome(a, b, c, d, c, b);
                     }
                 }
                 else
                 {
                        registerPalindrome(a, b, c, c, b, a);
                 }
            }
        }
    }
}

void factorize(Palindrome* mPal)
{
   int intPal = mPal->toInt();
   for(int i = 100; i < 1000; ++i)
   {
       if(intPal % i == 0)
       {
           int possible_factor = intPal / i;
           if(possible_factor > 99 && possible_factor < 1000)
           {
               std::cout << intPal << " = " << i << " x " << possible_factor << std::endl;
           }
       }
   } 
}

int main()
{
    generatePalindromes();
    std::for_each(Collection.begin(), Collection.end(), factorize);
    return 0;
}
