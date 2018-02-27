#include <iostream>
using namespace std;

bool findInMatrix(int* matrix, int rows, int columns, int target)
{
    bool found_flag = false;

    if(matrix != NULL && rows > 0 && columns > 0)
    {

        cout << "target is: " << target << "\n";
        int row = 0;
        int col = columns - 1;
        while(row < rows && col >= 0)
        {
            if(matrix[row * columns + col] == target)
            {
                found_flag = true;
                break;
                //return found_flag;
            }
            else if(matrix[row * columns + col] > target)
            {
                cout << "large\n";
                cout << row << ", " << col << "\n";
                cout << matrix[row * columns + col] << "\n";

                col--;
            }
            else
            {
                cout << "small\n";
                cout << row << ", " << col << "\n";
                cout << matrix[row * columns + col] << "\n";
                row++;
            }
        }
    }

    cout << found_flag << "\n";
    return found_flag;

}

int main()
{
    int matrix[] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};

    std::cout << findInMatrix(matrix, 4, 4, 11) << "\n";

}