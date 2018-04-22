class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0)
            return false;
        
        
        map<int, int> Map;
        
        while(true)
        {
            int sum = 0;
            while(n)
            {
                sum += (n % 10) * (n % 10);
                n = n / 10;
            }
            
            cout << sum << endl;
            
            n = sum;
            if(Map[sum]++ > 0)
                break;
        } 
        return n == 1;

    }
};
