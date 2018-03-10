#include <iostream>
int MaxDiff(int* numbers, unsigned length)
{
    if(numbers == NULL || length < 2)
        return 0;

    int minUpToNow = numbers[0];
    int maxDiff = numbers[1] - minUpToNow;

    for(int i = 2; i < length; i++)
    {
        if(numbers[i - 1] < minUpToNow)
            minUpToNow = numbers[i - 1];

        if(maxDiff < numbers[i] - minUpToNow)
            maxDiff = numbers[i] - minUpToNow;
    }

    return maxDiff;
}