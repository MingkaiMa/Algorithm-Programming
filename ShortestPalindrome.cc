//reference: https://blog.csdn.net/qq508618087/article/details/51641392

class Solution {
public:
    
    
    string shortestPalindrome(string s) {
        
        string str = s;
        reverse(str.begin(), str.end());
        str = s + '#' + str;
        int len1 = s.size();
        int len2 = str.size();
        vector<int> vec(len2, 0);
        
        for(int i = 1; i < len2; i++)
        {
            int k = vec[i - 1];
            while(k > 0 && str[k] != str[i])
                k = vec[k - 1];
            vec[i] = (k += str[i] == str[k]);
        }
        return str.substr(len1 + 1, len1 - vec[len2 - 1]) + s;
        
    }
};
