class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        if(nums.size() == 1)
        {
            if(nums[0] >= s)
                return 1;
            return 0;
        }
        
        
        if(nums[0] >= s)
            return 1;
        
        
        int small = 0;
        int big = 1;
        int curSum = nums[small] + nums[big];
        
        int minLen = INT_MAX;
        
        while(big < nums.size())
        {
            if(curSum < s)
            {
                big++;
                curSum += nums[big];
            }
            else
            {
                int curLen = big - small + 1;
                if(curLen < minLen)
                    minLen = curLen;
                
                curSum -= nums[small];
                
                if(small == big)
                {
                    big++;
                    small++;
                    curSum += nums[big];
                }
                else
                {
                    small++;   
                }
            }
        }
        
        if(minLen == INT_MAX)
            return 0;
        
        return minLen;
    }
};
