/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

/*
The product of two 3-digit numbers is a number of 6 or less digits, 999x999 = 998001

1st approach) Create all 6-digit palindromes abccba and 5 digit palindromes 0abcba and decompose in 3-digit products.
2nd approach) Generate all 3-digit numbers, multiply them and check for palindromes within.
*/

class Palindrome
{
  public:
    Palindrome() {}
  private:
    int palindrome[6];
    int* mPalindrome;
};
