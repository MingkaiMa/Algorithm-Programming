class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() <= 10)
            return {};
        
        map<string, int> Map;
        
        int i = 0, j = 10;
        
        while(j <= s.size())
        {
            string subst(s.begin() + i, s.begin() + j);
            // cout << i << " " << j << endl;
            // cout << subst << endl;
            if(Map.count(subst) < 1)
                Map[subst] = 1;
            else
                Map[subst] += 1;
            
            i++;
            j++;
        }
        
        vector<string> res;
        
        map<string, int>::iterator it;
        for(it = Map.begin(); it != Map.end(); it++)
        {
            if(it->second > 1)
                res.push_back(it->first);
        }
        
        return res;
        
    }
};
