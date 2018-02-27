#include <iostream>
using namespace std;

int getMin(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
    {
        return -100;
    }

    int index1 = 0;
    int index2 = length - 1;
    int middle = index1;

    while(numbers[index1] >= numbers[index2])
    {
        if(index2 - index1 == 1)
        {
            middle = index2;
            break;
        }

        middle = (index2 + index1) / 2;
        if(numbers[middle] > numbers[index1])
        {
            index1 = middle;
        }
        else if(numbers[middle] < numbers[index2])
        {
            index2 = middle;
        }
    }

    return numbers[middle];
}


int main()
{
    int numbers[] = {3,4,5,2};
    cout << getMin(numbers, 4) << "\n";
}