class Solution {
public:
    
    
    int CeilIndex(vector<int>& nums, int l, int r, int key)
    {
        while(r - l > 1)
        {
            int m = l + (r - l) / 2;
            if(nums[m] >= key)
                r = m;
            else
                l = m;
        }
        
        return r;
    }
    
    bool lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        vector<int> tail(nums.size(), 0);
        int length = 1;
        
        tail[0] = nums[0];
        
        for(size_t i = 1; i < nums.size(); i++){
            if(nums[i] < tail[0])
                tail[0] = nums[i];
            
            else if(nums[i] > tail[length - 1])
                tail[length++] = nums[i];
            
            else
                tail[CeilIndex(tail, -1, length - 1, nums[i])] = nums[i];
        
            if(length >= 3)
                return true;
        }
        
        return length >= 3;
    }
    
    bool increasingTriplet(vector<int>& nums) {
        return lengthOfLIS(nums);
    }
};
