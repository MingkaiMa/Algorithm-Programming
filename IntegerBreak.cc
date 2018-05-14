class Solution {
public:
    int integerBreak(int n) {
        if(n <= 2)
            return 1;
        
        
        vector<int> array(n + 1);
        array[0] = 1;
        array[1] = 1;
        array[2] = 1;
        

        for(int i = 3; i <= n; i++)
        {
            int res = -1;

            for(int j = 1; j <= i / 2; j++)
            {

                int r1 = j * (i - j);
                int r2 = array[j] * array[i - j];
                int r3 = j * array[i - j];
                int r4 = (i - j) * array[j];

                res = max(res, max(r1, max(r2, max(r3, r4))));
            }
            
            array[i] = res;
        }

        return array[n];
    }
};
