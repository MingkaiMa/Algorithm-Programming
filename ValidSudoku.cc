#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int array[9] = {0};

        bool flag = true;

        //check for each line

        for(int i = 0; i < board.size(); i++)
        {
            memset(array, 0, sizeof(array));
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] != '.')
                {
                    if(array[board[i][j] - '1'] == 0)
                        array[board[i][j] - '1'] = 1;

                    else
                    {
                        return false;
                    }

                }
            }
        }

        for(int i = 0 ; i < 9; i++)
        {
            memset(array, 0, sizeof(array));
            for(int j = 0; j < 9; j++)
            {
                if(board[j][i] != '.')
                {
                    if(array[board[j][i] - '1'] == 0)
                        array[board[j][i] - '1'] = 1;
                    else
                    {
                        return false;
                    }
                }
            }
        }


        for(int i = 0; i < 9; i++)
        {

            for(int j = 0; j < 9; j++)
            {
                if(i % 3 == 0 && j % 3 == 0)
                {
                    memset(array, 0, sizeof(array));
                    for(int ii = i; ii < i + 3; ii++)
                    {
                        for(int jj = j; jj < j + 3; jj++)
                        {
                            if(board[ii][jj] != '.')
                            {
                                if(array[board[ii][jj] - '1'] == 0)
                                    array[board[ii][jj] - '1'] = 1;
                                else
                                    return false;
                            }
                        }
                    }
                }
            }
        }


        return flag;
    }
};

int main()
{
    int array[10] = {0};

    for(int i = 0; i < 10; i++)
    {
        array[i] = 1;
    }

    memset(array, 0, sizeof(array));
    for(int i = 0; i < 10; i++)
    {
        cout << array[i] << ", ";
    }
    cout << "\n";
}