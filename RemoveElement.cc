class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        if(nums.size() == 0)
        {
            return 0;
        }

        int i = 0;
        int j = 0;

        while(i < nums.size() && j < nums.size())
        {
            if(nums[j] == val)
            {
                while(j < nums.size() && nums[j] == val)
                {
                    j++;
                }

                if(j == nums.size())
                    break;

                nums[i] = nums[j];
                i++;
                j++;

            }
            else
            {
                nums[i] = nums[j];
                i++;
                j++;
            }
        }

        return i;
    }
};