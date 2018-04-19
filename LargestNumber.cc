class Solution {
public:
    
    static bool myCompare(string x, string y)
    {
        int i = 0, j = 0;

        while(i < x.size() && j < y.size())
        {
            if(x[i] - '0' == y[j] - '0')
            {
                i++;
                j++;
                continue;
            }
            
            if(x[i] - '0' > y[j] - '0')
                return true;
            
            if(x[i] - '0' < y[j] - '0')
                return false;
        }

        
        if(i == x.size() && j == y.size())
            return false;
        
        if(i == x.size() || j == y.size())
        {

            string n1 = x + y;
            string n2 = y + x;
            
            for(int i = 0; i < n1.size(); i++)
            {
                if(n1[i] - '0' == n2[i] - '0')
                    continue;
                
                if(n1[i] - '0' > n2[i] - '0')
                    return true;
                else
                    return false;
            }

        }

        return true;
    }
    
    string largestNumber(vector<int>& nums) {
        vector<string> numString;
        
        for(auto& n: nums)
            numString.push_back(to_string(n));

        sort(numString.begin(), numString.end(), myCompare);
        
        string res = "";
        
        for(auto& s: numString)
            res += s;
        
        int nonZero = 0;
        
        while(nonZero < res.size() && res[nonZero] == '0')
            nonZero++;
        
        if(nonZero == res.size())
            return "0";
        
        return string(res.begin() + nonZero, res.end());    
    }
};
