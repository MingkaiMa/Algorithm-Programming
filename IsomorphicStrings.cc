class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() == 0 && t.size() == 0)
            return true;
        
        
        map<char, int> Map1;
        map<char, int> Map2;
        
        int count1 = 1;
        string s1 = "";
        for(auto& ch: s)
        {
            if(Map1.count(ch) <= 0)
            {
                Map1[ch] = count1;
                s1 += to_string(count1);
                
                count1++;
            }
            else
            {
                s1 += to_string(Map1[ch]);
            }
        }
        
        int count2 = 1;
        string s2 = "";
        for(auto& ch: t)
        {
            if(Map2.count(ch) <= 0)
            {
                s2 += to_string(count2);
                Map2[ch] = count2;
                count2++;
            }
            else
            {
                s2 += to_string(Map2[ch]);
            }
        }
        
        
        return s1 == s2;
        
        return true;
        
    }
};
