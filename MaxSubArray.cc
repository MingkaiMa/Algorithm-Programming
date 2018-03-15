class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() <= 0)
            return INT_MIN;
        
        int max_so_far = 0;
        int max_end_here = 0;
        
        
        for(int i = 0; i < nums.size(); i++)
        {
            
            max_end_here = max(0, max_end_here + nums[i]);
            max_so_far = max(max_so_far, max_end_here);
        }
        
        
        if(max_so_far == 0)
        {
            int maxR = nums[0];
            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i] > maxR)
                    maxR = nums[i];
            }
            
            return maxR;
        }
        
        return max_so_far;
    }
};
