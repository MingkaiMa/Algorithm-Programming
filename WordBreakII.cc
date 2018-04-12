class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        vector<vector<string>> dp(s.size() + 1);
        dp[0].push_back(string(""));
        
        for(size_t i = 0; i < s.size(); i++)
        {
            if(dp[0].empty() == true)
                continue;
            
            for(size_t length = 1; i + length <= s.size(); length++)
            {
                if(find(wordDict.begin(), wordDict.end(), s.substr(i, length)) == wordDict.end())
                    continue;
                
                dp[i + length].push_back(s.substr(i, length));
            }
        }
        
        dfs(string(), dp, s.size());
        
        return ret;
        
    }

private:
        void dfs(string str, vector<vector<string>>& dp, size_t now)
        {
            if(now == 0)
            {
                ret.push_back(str);
                return;
            }
            
            for(auto it = dp[now].begin(); it != dp[now].end(); it++)
            {
                string new_str = (str.empty() ? *it: *it + " " + str);
                dfs(new_str, dp, now - it->size());
            }
        }
    
    vector<string> ret;
};
