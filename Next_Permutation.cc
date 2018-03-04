class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        if(nums.size() == 0 || nums.size() == 1)
        {
            return;
        }

        if(nums.size() == 2)
        {
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;

            return;
        }


        int count_flag = nums.size() - 1;

        while(count_flag - 1 >= 0 && nums[count_flag - 1] >= nums[count_flag])
        {
            count_flag--;
        }

        if(count_flag == nums.size() - 1)
        {
            int temp = nums[count_flag];
            nums[count_flag] = nums[count_flag - 1];
            nums[count_flag - 1] = temp;
            return;
        }


        if(count_flag == 0)
        {
            sort(nums.begin(), nums.end());
            return;
        }


        int key_value = nums[count_flag - 1];

        int count2 = nums.size() - 1;
        int count_find = -1;

        while(count2 >= 0)
        {
            if(nums[count2] > key_value)
            {
                count_find = count2;
                break;
            }

            count2--;
        }


        nums[count_flag - 1] = nums[count_find];
        nums[count_find] = key_value;


        sort(nums.begin() + count_flag, nums.end());

        return;

    }
};