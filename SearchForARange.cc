//almost same with getNumberofK
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {



        if(nums.size() == 0)
        {
            vector<int> L = {-1, -1};

            return L;
        }


        int left = 0;
        int right = nums.size() - 1;
        int firstAppear = -1;


        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                if(mid > 0 && nums[mid - 1] != target || mid == 0)
                {
                    firstAppear = mid;
                    break;
                }
                else
                {
                    right = mid - 1;
                }

            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }


        left = 0;
        right = nums.size() - 1;
        int lastAppear = -1;

        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
            {
                if(mid + 1 < nums.size() && nums[mid + 1] != target || mid == nums.size() - 1)
                {
                    lastAppear = mid;
                    break;
                }
                else
                {
                    left = mid + 1;
                }

            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else
                left = mid + 1;
        }


        vector<int> R;
        R.push_back(firstAppear);
        R.push_back(lastAppear);

        return R;

    }
};