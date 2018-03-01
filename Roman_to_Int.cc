using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        map<char, int> dic = {{'M', 1000},{'D', 500} ,{'C', 100},{'L', 50},{'X', 10},{'V', 5},{'I', 1}};

        for(int i = 0; i < s.size() - 1; i++){
            if (dic[s[i]] < dic[s[i + 1]]){

                res -= dic[s[i]];
            }
            else{
                res += dic[s[i]];
            }
        }

        return res + dic[s[s.size() - 1]];

    }
};