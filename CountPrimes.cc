class Solution {
public:
    int countPrimes(int n) {
        
        
        if(n <= 2)
            return 0;
        
        
        int n_index = (n - 1) / 2;
        
        bool* primes_sieve = new bool[n_index + 1];
        for(int i = 0; i < n_index + 1; i++)
            primes_sieve[i] = true;
        
        for(int k = 1; k < (round(sqrt(n)) + 1) / 2; k++)
        {
            if(primes_sieve[k])
            {
                for(int i = 2 * k * (k + 1); i < n_index + 1; i += (2 * k + 1))
                    primes_sieve[i] = false;
            }
        }
        
        int count = 1;
        int nn = 1;
        
        vector<int> res;
        res.push_back(2);
        
        for(;nn < n_index + 1; nn++)
        {
            if(primes_sieve[nn])
            {
                count += 1;

                res.push_back(2 * nn + 1);
            }
        }

        
        if(res[res.size() - 1] == n)
            count = res.size() - 1;
        else
            count = res.size();

        return count;
        
    }
};
