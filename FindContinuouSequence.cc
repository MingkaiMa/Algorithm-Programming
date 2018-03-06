#include <iostream>
using namespace std;

void printSequence(int small, int big)
{
    for(int i = small; i <= big; i++)
        cout << i << " ";

    cout << "\n";
}

void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return;


    int small = 1;
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;

    while(small < middle)
    {
        if(curSum == sum)
            printSequence(small, big);

        while(curSum > sum && small < middle)
        {
            curSum -= small;
            small++;

            if(curSum == sum)
                printSequence(small, big);
        }

        //cout << big << "\n";
        big++;
        curSum += big;

    }
}

int main()
{

    FindContinuousSequence(9);
}