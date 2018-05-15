class Solution {  
    typedef pair<int, int> data;  
public:  
    vector<int> topKFrequent(vector<int>& nums, int k) {  
        unordered_map<int, int> hash;  
        priority_queue<data, vector<data>, greater<data>> heap;  
        vector<int> ret;  
          
        for(int num:nums)   
            hash[num]++;  
          
        for(auto it:hash) {  
            heap.push(make_pair(it.second, it.first));  
            if(heap.size() > k) heap.pop();  
        }  
          
        while(!heap.empty()) {  
            ret.push_back(heap.top().second);  
            heap.pop();  
        }  
          
        return ret;  
    }  
}; 
