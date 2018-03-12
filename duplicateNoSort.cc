#include <iostream>

using namespace std;

int getCount(const int* numbers, int length, int start, int end)
{
    if(numbers == NULL || length <= 0)
        return -1;

    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(numbers[i] >= start && numbers[i] <= end)
            ++count;
    }

    return count;
}

int getDuplicate(const int* numbers, int length)
{

    if(numbers == NULL || length <= 0)
        return -1;


    int start = 1;
    int end = length - 1;

    while(start <= end)
    {
        int mid = (start + end) >> 1;
        int count = getCount(numbers, length, start, end);


        if(start == end)
        {
            if(count > 1)
            {
                return start;
            }
            else
                break;

        }

        if(count > (end - start + 1))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}