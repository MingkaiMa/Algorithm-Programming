class Solution {
public:

    bool currentValid(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0 ; i < board.size(); i++)
        {
            if(board[i][col] == c)
                return false;
        }

        for(int i = 0; i < board[0].size(); i++)
        {
            if(board[row][i] == c)
            {
                return false;
            }
        }

        for(int i = row / 3 * 3; i < row / 3 * 3 + 3; i++)
        {
            for(int j = col / 3 * 3; j < col / 3 * 3 + 3; j++)
            {
                if(board[i][j] == c)
                    return false;
            }
        }
        return true;
    }

    bool getSolu(vector<vector<char>>& board)
    {
        if(board.size() == 0)
            return false;

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '.')
                {
                    for(char c = '1'; c <= '9'; c++)
                    {
                        if(currentValid(board, i, j, c))
                        {
                            board[i][j] = c;
                            if(getSolu(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }

            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        getSolu(board);
    }
};