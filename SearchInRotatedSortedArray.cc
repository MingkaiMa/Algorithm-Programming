class Solution {
public:
    int BinarySearch(vector<int>& nums, int target, int left, int right)
    {

        int count = -1;
        while(left <= right)
        {
            int middle = (left + right) / 2;
            if(nums[middle] == target)
            {
                count = middle;
                break;
            }

            if(nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }

        return count;
    }

    
    int search(vector<int>& nums, int target) {

        if(nums.size() == 0)
        {
            return -1;
        }

        if(nums.size() == 1)
        {
            return nums[0] == target ? 0 : -1;
        }


        int pivot = 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            if(nums[i] > nums[i + 1])
            {
                pivot = i + 1;
                break;
            }
        }




        cout << pivot << "\n";

        if(nums[pivot] == target)
        {
            return pivot;
        }

        if(target < nums[pivot])
        {
            return -1;
        }
        if(target > nums[pivot] && target <= nums[nums.size() - 1])
        {
            return BinarySearch(nums, target, pivot, nums.size() - 1);
        }
        else
        {
            return BinarySearch(nums, target, 0, pivot);
        }



        return -1;

    }
};