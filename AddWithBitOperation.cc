#include <iostream>

using namespace std;

int add(int num1, int num2)
{
    int sum, carry;
    do
    {
        cout << "num1: " << num1 << " num2: " << num2 << endl;
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }
    while(num2 != 0);

    return num1;
}

int main()
{
    int num1 = 4, num2 = 6;
    cout << add(num1, num2) << endl;
}