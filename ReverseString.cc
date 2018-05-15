class Solution {
public:
    string reverseString(string s) {
        if(s.size() <= 1)
            return s;
        
        int left = 0;
        int right = s.size() - 1;
        
        while(left < right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
        
        return s;
        
    }
};
