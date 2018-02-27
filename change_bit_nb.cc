#include <iostream>


int getChangedBitNb(int n, int m)
{
    int middle = n ^ m;

    int count = 0;
    while(middle)
    {
        count += 1;
        middle = middle & (middle - 1);
    }

    return count;
}


int main()
{
    std::cout << getChangedBitNb(10, 13) << "\n";
}