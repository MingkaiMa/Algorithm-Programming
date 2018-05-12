class Solution {
public:
    bool isValidSerialization(string preorder) {

        vector<string> array;
        
        int i = 0;
        while(i < preorder.size())
        {
            while(preorder[i] == ',')
                i++;
            
            int j = i;
            
            while(j < preorder.size() && preorder[j] != ',')
                j++;
            
            
            
            string tmp(preorder.begin() + i, preorder.begin() + j);
            array.push_back(tmp);
            i = j;
        }

        int count = 0;
        
        for(int i = 0; i < array.size() - 1; i++)
        {
            if(array[i] == "#")
            {
                if(count == 0)
                    return false;
                count--;
            }
            else
                count++;
        }
        
        
        return count == 0 && array.back() == "#";
    }
};
