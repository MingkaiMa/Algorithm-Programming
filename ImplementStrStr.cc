class Solution {
public:
    int strStr(string haystack, string needle) {

        if(haystack.size() == 0 && needle.size() == 0)
        {
            return 0;
        }

        if(haystack.size() != 0 && needle.size() == 0)
        {
            return 0;
        }

        if(haystack.size() < needle.size())
        {
            return -1;
        }
        if(haystack.size() <= 0 || needle.size() <= 0)
        {
            return -1;
        }

        int i = needle.size() - 1;
        int j = needle.size() - 1;

        int flag = 0;

        int result = -1;

        while(i < haystack.size())
        {
            if(haystack[i] == needle[j])
            {

                if(j == needle.size() - 1)
                {
                    flag = i;
                }


                if(j == 0)
                {
                    result = i;
                    break;
                }
                else
                {
                    i--;
                    j--;
                    continue;
                }
            }

            else
            {

                if(j != needle.size() - 1)
                {
                    i = flag + 1;
                }
                else
                {
                    i++;
                }

                j = needle.size() - 1;

                //i++;
                continue;
            }

        }



        return result;

    }
};