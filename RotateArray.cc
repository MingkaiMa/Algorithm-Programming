class Solution {
public:
    
    void myOwnSwap(vector<int>& nums, int start, int end)
    {
        while(start < end)
        {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
    
    
    void rotate(vector<int>& nums, int k) {
        
        if(nums.size() == k)
            return;
        
        if(nums.size() < k)
        {
            k = k % nums.size();
        }
        
        int n = nums.size();
        
        myOwnSwap(nums, 0, n - k - 1);
        myOwnSwap(nums, n - k, n - 1);
        myOwnSwap(nums, 0, n - 1);
        
    }
};
