#include <iostream>
#include <algorithm>
using namespace std;

int MaxValueGift(int MatrixOfValue[][4], int rows, int columns)
{
    int** M = new int*[rows];

    for(int i = 0; i < rows; i++)
    {
        M[i] = new int[columns];
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            M[i][j] = 0;
        }
    }


    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {

//            cout << "****\n";
//            for(int i = 0; i < rows; i++)
//            {
//                for(int j = 0; j < columns; j++)
//                {
//                    cout << M[i][j] << ", ";
//
//                }
//                cout << "\n";
//            }



            if(i == 0 && j == 0)
            {
                M[i][j] = MatrixOfValue[i][j];
                continue;
            }

            if(i == 0 && j != 0)
            {
                M[i][j] = M[i][j - 1] + MatrixOfValue[i][j];
                continue;
            }

            if(i != 0 && j == 0)
            {

                //cout << "i is: j is: " << i << ", " << j << "\n";
                //cout << MatrixOfValue[i][j] << "\n";
                //cout << MatrixOfValue[i - 1][j] << "\n";
                M[i][j] = M[i - 1][j] + MatrixOfValue[i][j];
                continue;
            }


            M[i][j] = max(M[i - 1][j], M[i][j - 1]) + MatrixOfValue[i][j];
        }
    }

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << M[i][j] << ", ";

        }
        cout << "\n";
    }

    int result = M[rows - 1][columns - 1];
    for(int i = 0; i < rows; i++)
    {
        delete[] M[i];
    }
    delete[] M;

    return result;
}

int main()
{
    int MatrixOfValue[4][4] = {{1, 10, 3, 8},
                             {12, 2, 9, 6},
                             {5, 7, 4, 11},
                             {3, 7, 16, 5}};
    int rows = 4;
    int columns = 4;

    //cout << MatrixOfValue[2][2] << "\n";
    int n = MaxValueGift(MatrixOfValue, rows, columns);
    cout << n << "\n";
}