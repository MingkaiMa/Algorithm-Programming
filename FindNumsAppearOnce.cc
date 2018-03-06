#include <iostream>
using namespace std;

unsigned int FIndFirstBitIs1(int num)
{
    int indexBit = 0;
    while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
    {
        num = num >> 1;
        ++indexBit;
    }

    return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
    if(data == NULL || length < 2)
        return;

    int resultExclusiveOR = 0;
    for(int i = 0; i < length; i++)
    {
        resultExclusiveOR ^= data[i];
        //cout << resultExclusiveOR << "\n";
    }

    cout << resultExclusiveOR << "\n";


    unsigned int indexOf1 = FIndFirstBitIs1(resultExclusiveOR);
    cout << indexOf1 << "\n";


    *num1 = *num2 = 0;
    for(int j = 0; j < length; j++)
    {
        if(IsBit1(data[j], indexOf1))
            *num1 ^= data[j];
        else
            *num2 ^= data[j];
    }
}

int main()
{
    int n1 = 0;
    int n2 = 0;
    int data[] = {2, 4, 3, 6, 3, 2, 5, 5};
    FindNumsAppearOnce(data, 8, &n1, &n2);
    cout << n1 << ", " << n2 << "\n";
}