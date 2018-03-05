#include <iostream>
using namespace std;

int getNumberSameAsIndex(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        return -1;


    int left = 0;
    int right = length - 1;



    while(left <= right)
    {
        int middle = (left + right) >> 1;
        if(middle == numbers[middle])
        {
            return middle;
        }

        else if(middle > numbers[middle])
            left = middle + 1;

        else
            right = middle - 1;
    }

    return -1;
}

int main()
{
    int numbers[] = {-3, -2, -1, 0, 3};
    cout << getNumberSameAsIndex(numbers, 5) << "\n";
}