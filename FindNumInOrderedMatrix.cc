#include <iostream>

using namespace std;

bool Find(int* matrix, int rows, int columns, int number)
{
    if(numbers == NULL)
        return false;


    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int col = columns - 1;
        while(row < rows && col >= 0)
        {
            if(matrix[row * col + col] == number)
                return true;

            else if(matrix[row * col + col] > number)
                col--;

            else
                row++;
        }
    }
    return false;
}