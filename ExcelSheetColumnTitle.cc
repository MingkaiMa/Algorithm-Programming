class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 0)
            return "";
        
        char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        
        cout << alphabet['A' - 'A'] << endl;
        
        string res = "";
        
        while(n != 0)
        {
            int reminder = n % 26;
            if(reminder == 0)
            {
                res += 'Z';
                n = n / 26;
                n -= 1;
            }
            else
            {
                res += alphabet[reminder - 1];
                n = n / 26;
            }
            
        }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};
