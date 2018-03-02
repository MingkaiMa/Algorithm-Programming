#include <iostream>
#include <vector>

using namespace std;


//Solution 1: my own
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();

        int curr = nums[0];
        int newLength = 1;

        int i = 1;
        while(i < nums.size())
        {
            if(curr != nums[i])
            {
                newLength++;
                curr = nums[i];
                i++;
                continue;
            }

            nums.erase(nums.begin() + i);

        }


        return newLength;
    }
};


//Solution 2:
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();

        int i = 0;
        for(int j = 1; j < nums.size(); j++)
        {
            if(nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
