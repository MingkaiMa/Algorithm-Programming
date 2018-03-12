class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> R;
        unordered_map<string, vector<string>> m;

        for(int i = 0; i < strs.size(); i++)
        {
            vector<int> countList(26, 0);
            string s = "";
            for(int j = 0; j < strs[i].size(); j++)
            {
                countList[strs[i][j] - 'a']++;
            }

            for(int k = 0; k < 26; k++)
            {
                s += to_string(countList[k]);
            }

            m[s].push_back(strs[i]);

        }

        for(auto a: m)
        {
            R.push_back(a.second);
        }

        return R;
    }
};