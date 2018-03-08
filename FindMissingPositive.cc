class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() <= 0)
            return 1;

        int maxValue = nums[0];
        int minValue = nums[0];

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > maxValue)
                maxValue = nums[i];

            if(nums[i] < minValue)
                minValue = nums[i];
        }

        int* C = new int[maxValue + 1];

        for(int i = 0; i < maxValue + 1; i++)
            C[i] = 0;

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] >= 0)
            {
                C[nums[i]] = C[nums[i]] + 1;
            }


        // for(int i = 0; i < maxValue + 1; i++)
        //     cout << C[i] << ", ";


        int ii = 1;

        int result;
        for(ii = 1; ii < maxValue + 1; ii++)
        {
            if(C[ii] == 0)
            {
                result = ii;
                break;
            }
                //return ii;
        }

        delete[] C;

        result = ii;
        return result;

    }
};