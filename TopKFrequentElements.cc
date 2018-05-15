class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m1;
        for(auto& i: nums)
        {
            if(m1.count(i) <= 0)
                m1[i] = 1;
            else
                m1[i] += 1;
        }
        
        priority_queue<pair<int, int>> p;
        
        vector<int> res;
        
        for(auto it: m1)
            p.push(make_pair(it.second, it.first));
        
        for(int i = 0; i < k; i++)
        {
            res.push_back(p.top().second);
            p.pop();
        }
        return res;
    }
};
