#include <iostream>

int Add(int n1, int n2)
{
    int sum, carry;
    do
    {
        sum = n1 ^ n2;
        carry = (n1 & n2) << 1;

        n1 = sum;
        n2 = carry;
    }
    while(n2 != 0);
    return n1;
}