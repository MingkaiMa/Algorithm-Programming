class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 0)
            return false;
        
        if(nums.size() == 1)
            return true;
        
        int array[nums.size() - 1];
        for(int i = 0; i < nums.size() - 1; i++)
        {
            array[i] = 0;
        }
        
        int targetIndex = nums.size() - 1;
        
        for(int i = nums.size() - 2; i >= 0; i--)
        {
            if(i + nums[i] >= targetIndex)
            {
                array[i] = 1;
                continue;
            }
            
            int maxLeap = nums[i];
            int flag = 0;
            for(int c = 1; c <= maxLeap; c++)
            {
                if(array[i + c] == 1)
                {
                    array[i] = 1;
                    flag = 1;
                    break;
                }
            }
            
            if(flag == 0)
                array[i] = 0;
            
        }
        
        return array[0] == 1;
        
    }
};
