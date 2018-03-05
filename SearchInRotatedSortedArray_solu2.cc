class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();

        if(n == 0)
        {
            return -1;
        }

        if(n == 1)
        {
            return nums[0] == target ? 0 : -1;
        }


        int left = 0;
        int right = n - 1;

        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }


        int minIndex = left;


        if(nums[minIndex] == target)
        {
            return minIndex;
        }

        int start = (target <= nums[n - 1]) ? minIndex : 0;
        int end = (target > nums[n - 1]) ? minIndex : n - 1;

        while(start <= end)
        {
            int mid = (start + end) >> 1;
            if(nums[mid] == target)
            {
                return mid;
            }
            if(target > nums[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }



        return -1;

    }
};