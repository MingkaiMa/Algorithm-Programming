##include <iostream>

void print1toMax(int n)
{
    if(n <= 0)
        return;

    char* number = new char[n + 1];
    numbers[n] = '\0';

    for(int i = 0; i < 10; i++)
    {
        number[0] = i + '0';
        recur_func(number, n, 0);
    }

    delete[] number;
}


void recur_func(char* number, int length, int index)
{
    if(index == length - 1)
    {
        PrintFunc(number);
        return;
    }

    for(int i = 0; i < 10; i++)
    {
        number[index + 1] = i + '0';
        recur_func(number, length, index + 1);
    }
}