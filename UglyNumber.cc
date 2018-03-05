#include <iostream>
using namespace std;

int get_min(int x, int y, int z)
{
    int min = (x < y) ? x : y;
    min = (z < min) ? z : min;

    return min;
}

int GetUglyNumber(int index)
{
    if(index <= 0)
    {
        return 0;
    }

    int* UglyNumbers = new int[index];
    UglyNumbers[0] = 1;
    int nextIndex = 1;

    int* Mul2 = UglyNumbers;
    int* Mul3 = UglyNumbers;
    int* Mul5 = UglyNumbers;

    while(nextIndex < index)
    {
        int min_to_get = get_min(*Mul2 * 2, *Mul3 * 3, *Mul5 * 5);
        UglyNumbers[nextIndex] = min_to_get;

        while(*Mul2 * 2 <= UglyNumbers[nextIndex])
            ++Mul2;

        while(*Mul3 * 3 <= UglyNumbers[nextIndex])
            ++Mul3;

        while(*Mul5 * 5 <= UglyNumbers[nextIndex])
            ++Mul5;


        nextIndex++;
    }

    int ugly = UglyNumbers[nextIndex - 1];
    delete[] UglyNumbers;
    return ugly;
}

int main()
{
    cout << GetUglyNumber(20) << "\n";
}