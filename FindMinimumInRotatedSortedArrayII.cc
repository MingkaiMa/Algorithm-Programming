class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        
        int minres = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(minres > nums[i])
                minres = nums[i];
        }
        
        return minres;
    }
};
