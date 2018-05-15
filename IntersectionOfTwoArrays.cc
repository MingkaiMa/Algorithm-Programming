class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        
        for(auto& i: nums1)
        {
            if(m.count(i) <= 0)
                m[i] = 1;
        }
        
        vector<int> res;
        for(auto& i: nums2)
        {
            if(m.count(i) > 0)
            {
                if(find(res.begin(), res.end(), i) == res.end())
                    res.push_back(i);
            }
        }
        
        return res;
    }
};
