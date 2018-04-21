class Solution {
public:
    
    void colorMatrix(vector<vector<int>>& matrix, vector<vector<char>>& grid, int i, int j, int color)
    {
        
        if(grid[i][j] != '1')
            return;
        
        if(matrix[i][j] != 0)
            return;
        
        matrix[i][j] = color;
        
        if(j + 1 < matrix[0].size())
            colorMatrix(matrix, grid, i, j + 1, color);
        
        if(j - 1 >= 0)
            colorMatrix(matrix, grid, i, j - 1, color);
        
        if(i + 1 < matrix.size())
            colorMatrix(matrix, grid, i + 1, j, color);
        
        if(i - 1 >= 0)
            colorMatrix(matrix, grid, i - 1, j, color);
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0)
            return 0;
        
        int count = 1;
        
        vector<vector<int>> matrix(grid.size(), vector<int>(grid[0].size(), 0));
        
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {

                if(grid[i][j] != '1')
                    continue;
                
                if(matrix[i][j] != 0)
                    continue;
                colorMatrix(matrix, grid, i, j, count);
                count++;
                
            }
        }
        
        
        return count - 1;
    }
};
