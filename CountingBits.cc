class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1);
        
        for(int i = 0; i <= num; i++)
        {
            int n = i;
            int count = 0;
            while(n != 0)
            {
                n = n & (n - 1);
                count++;
            }
            
            res[i] = count;
        }
        return res;
    }
};
