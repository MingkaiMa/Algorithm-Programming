class Solution {
public:

    void findSol(vector<int>& candidates, int sum, vector<vector<int>>& R, vector<int>& r, int i)
    {
        if(sum < 0)
            return;

        if(sum == 0)
        {
            if(find(R.begin(), R.end(), r) == R.end())
            {
                R.push_back(r);

            }
            return;
        }

        while(i < candidates.size() && sum - candidates[i] >= 0)
        {
            r.push_back(candidates[i]);


            findSol(candidates, sum - candidates[i], R, r, i + 1);

            i++;

            r.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size() <= 0)
        {
            vector<vector<int>> R;
            return R;
        }
        sort(candidates.begin(), candidates.end());

        vector<int> r;
        vector<vector<int>> R;
        findSol(candidates, target, R, r, 0);

        return R;
    }
};