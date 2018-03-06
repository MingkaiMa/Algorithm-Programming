class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int length = nums.size();
        int left = 0;
        int right = length - 1;

        while(left <= right)
        {
            int mid = (left + right) / 2;

            if(nums[mid] == target)
            {
                return mid;
            }

            if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }

        if(right == -1)
        {
            return 0;
        }

        return left;
    }
};