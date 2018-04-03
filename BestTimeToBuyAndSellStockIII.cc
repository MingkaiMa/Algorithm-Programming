class Solution {
public:
    
    
    int getMax(vector<int>& diff)
    {
        int max_so_far = 0;
        int max_now = 0;

        
        for(int i = 0; i < diff.size(); i++)
        {
            max_now = max(0, max_now + diff[i]);
            max_so_far = max(max_so_far, max_now);
        }
        
        return max_so_far;
    }
    
    
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 0)
            return 0;
        
        vector<int> diff(prices.size() - 1);
        for(int i = 1; i < prices.size(); i++)
            diff[i - 1] = prices[i] - prices[i - 1];
        
        
        int maxOne = getMax(diff);
        
        int maxTotal = maxOne;
        for(int i = 0; i < diff.size(); i++)
        {
            for(int j = i + 1; j < diff.size(); j++)
            {
                vector<int> AheadHalf(diff.begin(), diff.begin() + j);
                vector<int> BackHalf(diff.begin() + j, diff.end());
                int maxAheadHalf = getMax(AheadHalf);
                int maxBackhalf = getMax(BackHalf);
                
                if(maxTotal < (maxAheadHalf + maxBackhalf))
                    maxTotal = maxAheadHalf + maxBackhalf;
            }
        }    
        

        return maxTotal;
    }
};
