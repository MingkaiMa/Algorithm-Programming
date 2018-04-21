class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() <= 0)
            return 0;
        
        
        vector<int> array(nums.size());
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0)
            {
                array[i] = nums[i];
                continue;
            }
            
            if(i <= 1)
            {
                array[i] = max(array[i - 1], nums[i]);
                continue;
            }
            
            array[i] = max(array[i - 2] + nums[i], array[i - 1]);
        }
        return array[nums.size() - 1];
    }
};
