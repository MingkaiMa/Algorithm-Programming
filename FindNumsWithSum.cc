#include <iostream>
using namespace std;

bool FindNumsWithSum(int data[], int length, int sum, int *num1, int *num2)
{
    if(data == NULL || length < 2)
    {
        return false;
    }

    bool flag = false;

    int left = 0;
    int right = length - 1;

    while(left < right)
    {
        if(data[left] + data[right] == sum)
        {
            *num1 = data[left];
            *num2 = data[right];
            flag = true;
            break;
        }

        if(data[left] + data[right] > sum)
            right--;

        else
            left++;
    }
    return flag;
}

int main()
{
    int data[] = {1, 2, 4, 7, 11, 15};
    int num1 = 0;
    int num2 = 0;
    cout << FindNumsWithSum(data, 6, 15, &num1, &num2) << "\n";
    cout << num1 << ", " << num2 << "\n";
}