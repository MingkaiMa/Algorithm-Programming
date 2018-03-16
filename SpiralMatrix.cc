class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        if(matrix.size() <= 0)
        {
            vector<int> R;
            return R;
        }
        
        int i_length = matrix.size();
        int j_length = matrix[0].size();
        
        int** aidMatrix = new int*[i_length];
        
        for(int i = 0; i < i_length; i++)
        {
            aidMatrix[i] = new int[j_length];
        }
        
        
        for(int i = 0; i < i_length; i++)
        {
            for(int j = 0; j < j_length; j++)
                aidMatrix[i][j] = 0;
        }
    
//         for(int i = 0; i < i_length; i++)
//         {
//             for(int j = 0; j < j_length; j++)
//                 cout << aidMatrix[i][j] << ", ";
            
//             cout << "\n";
//         }
        
        vector<int> R;
        
        int count = matrix.size() * matrix[0].size();
        
        int i = 0;
        int j = 0;
        

        
        while(count > 0)
        {
            //cout << "i : " << i << " j : " << j << "\n";
            R.push_back(matrix[i][j]);
            aidMatrix[i][j] = 1;
            
            if((i == 0 || aidMatrix[i - 1][j] == 1) && j >= 0 && j + 1 < j_length && aidMatrix[i][j + 1] == 0)
            {
                i = i;
                j += 1;
            }
            
            else if((j == j_length - 1 || aidMatrix[i][j + 1] == 1) && i >= 0 && i + 1 < i_length && aidMatrix[i + 1][j] == 0)
            {
                i += 1;
                j = j;
            }
            
            else if((i == i_length - 1 || aidMatrix[i + 1][j] == 1) && j - 1 >= 0 && j < j_length && aidMatrix[i][j - 1] == 0)
            {
                j -= 1;
            }
            
            else if((j == 0 || aidMatrix[i][j - 1] == 1) && i - 1 >= 0 && i < i_length && aidMatrix[i - 1][j] == 0)
            {
                i -= 1;
            }
            
            count--;
                    
        }
        
        return R;
        
    }
};
