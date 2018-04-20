class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        vector<int> bit(32, 0);
        
        for(int i = 0; i < 32; i++)
        {
            int mask = 1 << i;
            if(n & mask)
                bit[i] = 1;
        }

        int res = 0;
        for(int i = 0; i < 32; i++)
        {
            res += pow(2, 32 - 1 - i) * bit[i];
        }
        
        return res;
    }
};