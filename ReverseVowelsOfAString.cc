class Solution {
public:
    string reverseVowels(string s) {
        if(s.size() <= 1)
            return s;
        
        int left = 0;
        int right = s.size() - 1;
        
        vector<char> array = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        
        while(left < right)
        {
            while(find(array.begin(), array.end(), s[left]) == array.end())
                left++;

            while(find(array.begin(), array.end(), s[right]) == array.end())
                right--;
            
            if(left >= right)
                break;
            
            //cout << s[left] << "  " << s[right] << endl;
            swap(s[left], s[right]);
            left++;
            right--;
        }
        
        return s;
    }
};
