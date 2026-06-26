#include "palindrome.h"

int is_palindrome(unsigned long n)
{
    unsigned int base = n;
    unsigned int envers = 0;

    while (n >0)
    {
        envers = (envers * 10) + (n % 10);
        n = n / 10;
    }
    if (base == envers)
    {
        return 1;
    }
    return 0;
}