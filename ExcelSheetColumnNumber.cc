class Solution {
public:
    int titleToNumber(string s) {
        if(s.size() <= 0)
            return 0;
        

        if(s.size() == 1)
            return s[0] - 'A' + 1;
        
        
        
        int n = s.size();
        vector<int> benchmark(n + 1, 0);
        
        benchmark[1] = 1;
        
        for(int i = 2; i < n + 1; i++)
        {
            benchmark[i] = pow(26, (i - 1)) + benchmark[i - 1];
        }
        
        int res = 0;
        int exp = s.size() - 1;
        
        for(auto& c: s)
        {
            int diff = c - 'A';
            
            res += diff * pow(26, exp);
            exp--;
            
        }
        return res + benchmark[n];
    }
};
