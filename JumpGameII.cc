class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;

        if(nums.size() <= 2)
            return 1;

        int* array = new int[nums.size() - 1];

        for(int i = 0; i < nums.size() - 1; i++)
            array[i] = 0;

        int targetIndex = nums.size() - 1;


        int upToNowMin = -1;


        for(int i = nums.size() - 2; i >= 0; i--)
        {

            int maxStep = nums[i];
            if(maxStep + i >= targetIndex)
                array[i] = 1;

            else
            {
                int putValue = nums.size();


                if(i + maxStep >= upToNowMin)
                {
                    array[i] = 1 + array[upToNowMin];
                    continue;
                }


                for(int j = maxStep; j >= 1; j--)
                {

                    if(putValue > 1 + array[j + i])
                    {
                        putValue = 1 + array[j + i];

                    }
                }

                array[i] = putValue;
            }


            if(upToNowMin == -1)
            {
                upToNowMin = i;
            }

            else if(array[upToNowMin] > array[i])
            {
                upToNowMin = i;
            }



        }

        return array[0];


    }
};