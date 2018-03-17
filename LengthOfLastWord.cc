class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size() <= 0)
            return 0;
        
        int count = 0;
        
        
        int noneZero = s.size() - 1;
        for(int i = s.size() - 1; i >= 0; i--)
        {
            if(s[i] == ' ')
                noneZero--;
            else
                break;
                
        }
        
        
        for(int i = noneZero; i >= 0; i--)
        {
            if(s[i] != ' ')
                count++;
            else
                break;
        }
        
        return count;
        
    }
};
