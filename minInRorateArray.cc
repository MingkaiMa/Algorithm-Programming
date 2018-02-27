#include <iostream>
using namespace std;

int getMinInorder(int* numbers, int index1, int index2)
{
    int min_value = numbers[index1];
    for(int i = index1 + 1; i <= index2; i++)
    {
        if(min_value > numbers[i])
        {
            min_value = numbers[i];
        }
    }

    return min_value;

}

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

        if(numbers[middle] == numbers[index1] && numbers[index1] == numbers[index2])
        {
            return getMinInorder(numbers, index1, index2);
        }

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
    int numbers[] = {1, 0, 1, 1, 1};
    cout << getMin(numbers, 5) << "\n";
}