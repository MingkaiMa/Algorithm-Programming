class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        if(nums.size() == 1)
            return nums[0];
        
        return max(robCore(nums, 0, nums.size() - 2), robCore(nums, 1, nums.size() - 1));        
    }
    
    int robCore(vector<int>& nums, int first, int last)
    {
        int pLast = 0;
        int ppLast = 0;
        for(int i = first; i <= last; i++)
        {
            int tmp = pLast;
            pLast = max(ppLast + nums[i], pLast);
            ppLast = tmp;
        }
        return pLast;
    }
};
