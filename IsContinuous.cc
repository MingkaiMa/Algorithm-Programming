#include <iostream>
#include <algorithm>

using namespace std;

bool isContinuous(int* numbers, int length)
{
    if(numbers == NULL || length <= 0)
        return false;

    sort(numbers, numbers + length);

    int nbOfZero = 0;
    int nbOfGap = 0;

    for(int i = 0; i < length && numbers[i] == 0; i++)
        nbOfZero++;

    int small = nbOfZero;
    int big = small + 1;

    while(big < length)
    {
        if(numbers[big] == numbers[small])
            return false;

        nbOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        big++;
    }

    return (nbOfGap > nbOfZero) ? false : true;
}

int main()
{
    int numbers[5] = {0,1,3,5,6};
    int* n = numbers;
    cout << isContinuous(n, 5) << "\n";
}