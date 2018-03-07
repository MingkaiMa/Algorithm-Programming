class Solution {
public:
    string countAndSay(int n) {

        if(n <= 0)
            return "";

        if(n == 1)
            return "1";

        if(n == 2)
            return "11";


        string curr = "11";

        for(int i = 3; i <= n; i++)
        {
            string newStr = "";

            char curChar = curr[0];
            int count = 1;
            for(int j = 0; j < curr.size() - 1; j++)
            {
                if(curr[j] == curr[j + 1])
                {
                    count++;
                }
                else
                {
                    newStr += to_string(count);
                    newStr += curChar;
                    count = 1;
                    curChar = curr[j + 1];
                }
            }

            newStr += to_string(count);
            newStr += curChar;
            curr = newStr;
        }

        return curr;

    }
};