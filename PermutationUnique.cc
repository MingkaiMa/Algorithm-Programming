class Solution {
public:

    void Swap(int& n, int& m)
    {
        int temp = n;
        n = m;
        m = temp;
    }

    bool isSwap(vector<int>& nums, int left, int right)
    {
        for(int i = left; i < right; i++)
        {
            if(nums[i] == nums[right])
                return false;
        }

        return true;
    }

    void Core(vector<int>& nums, int startPos, vector<vector<int>>& L)
    {
        if(startPos == nums.size() - 1){
            L.push_back(nums);
            return;
        }

        for(int i = startPos; i < nums.size(); i++)
        {



            if(isSwap(nums, startPos, i)){
                Swap(nums[i], nums[startPos]);
                Core(nums, startPos + 1, L);
                Swap(nums[i], nums[startPos]);
            }
        }


    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if(nums.size() <= 0)
        {
            vector<vector<int>> L;
            return L;
        }

        vector<vector<int>> L;
        Core(nums, 0, L);
        return L;
    }
};