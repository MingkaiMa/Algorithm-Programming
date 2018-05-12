class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int res = 0;
        int index = 0;
        long miss = 1;
        
        while(miss <= n) 
        {
            if(index < nums.size() && nums[index] <= miss)
                miss += nums[index++];
            else
            {
                miss += miss;
                res++;
            }
        }
        
        return res;
    }
};
