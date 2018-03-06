#include <iostream>
using namespace std;

void printArray(int array[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << array[i] << " ,";
    }
    cout << "\n";
}
int FindNumsAppearOnceThree(int numbers[], int length)
{
    if(numbers == NULL || length <= 0)
        return -1;


    int bitSum[32] = {0};
    for(int i = 0; i < length; i++)
    {
        int bitMark = 1;
        for(int j = 31; j >=0; j--)
        {
            int bit = numbers[i] & bitMark;
            if(bit != 0)
                bitSum[j] += 1;

            bitMark = bitMark << 1;
        }

        printArray(bitSum, 32);
    }

    int result = 0;
    for(int i = 0; i < 32; i++)
    {
        result = result << 1;
        result += bitSum[i] % 3;

        cout << result << ", ";
    }
    cout << "\n";

    return result;
}


int main()
{
    int data[] = {1, 3, 3, 3, 1, 2, 1};
    cout << FindNumsAppearOnceThree(data, 7) << "\n";
}