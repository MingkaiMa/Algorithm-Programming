class Solution {
public:
    
    int Core(vector<vector<int>>& matrix, vector<vector<int>>& record, int x, int y, int lastVal)
    {
        if(x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size())
            return 0;
        
        if(matrix[x][y] > lastVal)
        {
            if(record[x][y] != 0)
                return record[x][y];
            int down = Core(matrix, record, x + 1, y, matrix[x][y]) + 1;
            int up = Core(matrix, record, x - 1, y, matrix[x][y]) + 1;
            int left = Core(matrix, record, x, y - 1, matrix[x][y]) + 1;
            int right = Core(matrix, record, x, y + 1, matrix[x][y]) + 1;
            record[x][y] = max(left, max(right, max(up, down)));
            return record[x][y];
        }
        
        return 0;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        
        vector<int> temp(matrix[0].size(), 0);
        vector<vector<int>> record(matrix.size(), temp);
        int longest = 0;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                longest = max(longest, Core(matrix, record, i, j, -1));
            }
        }
        
        return longest;
    }
};
