#include <iostream>

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
    if(numbers == NULL || columns <= 0 || rows <= 0)
        return;

    int start = 0;

    while(columns > start * 2 && rows > start * 2)
    {
        PrintMatrixCircle(numbers, columns, rows, start);
        ++start;
    }
}

void PrintMatrixCircle(int** numbers, int columns, int rows, int start)
{
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;

    //from left to right
    for(int i = start; i <= endX; i++)
    {
        int number = number[start][i];
        std::cout << number;
    }

    //right most from top to down
    if(start < endY)
    {
        for(int i = start + 1; i <= endY; i++)
        {
            int number = numbers[i][endX];
            std::cout << number;
        }
    }

    //from right to left
    if(start < endX && start < endY)
    {
        for(int i = endX - 1; i >= start; i--)
        {
            int number = numbers[endY][i];
            std::cout << number;
        }
    }

    //from down to top
    if(start < endX && start < endY - 1)
    {
        for(int i = endY- 1; i >= start + 1; i++)
        {
            int number = numbers[i][start];
            std::cout << number;
        }
    }
}