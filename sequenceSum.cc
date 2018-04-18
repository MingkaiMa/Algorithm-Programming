#include <iostream>
using namespace std;


void printRange(int i, int j)
{
    for(int x = i; x <= j; x++)
        cout << x << ", ";
    cout << endl;
}


void printSequence(int n)
{
    if(n < 3)
        return;

    int small = 1;
    int big = 2;
    int curSum = small + big;

    int middle = (1 + n) / 2;

    while(small < middle)
    {
        if(curSum == n)
            printRange(small, big);


        while(curSum > n && small < middle)
        {
            curSum -= small;
            small++;

            if(curSum == n)
                printRange(small, big);
        }

        big++;
        curSum += big;
    }
}

int main()
{
    int n = 15;
    printSequence(n);
}