#include <iostream>
#include <string>
using namespace std;

bool backtrackingCore(string s1, string s2, string s3, int start1, int start2, int start3)
{

//    cout << "start1 :" << start1 << "\n";
//    cout << "start2 :" << start2 << "\n";
//    cout << "start3 :" << start3 << "\n";

    // termination condition
    if(start3 == s3.size())
        return true;

    if(start1 == s1.size())
    {
        if(s2[start2] == s3[start3])
            if(backtrackingCore(s1, s2, s3, start1, start2 + 1, start3 + 1))
                return true;

        return false;
    }

    if(start2 == s2.size())
    {
        if(s1[start1] == s3[start3])
            if(backtrackingCore(s1, s2, s3, start1 + 1, start2, start3 +1))
                return true;

        return false;
    }


    if(s1[start1] == s3[start3])
    {
        if(backtrackingCore(s1, s2, s3, start1 + 1, start2, start3 + 1))
            return true;
    }

    //cout << "here start2: " << start2 << "\n";

    if(s2[start2] == s3[start3])
    {
        if(backtrackingCore(s1, s2, s3, start1, start2 + 1, start3 + 1))
            return true;
    }


    return false;
}

bool isInterleave(string s1, string s2, string s3) {

    int len1 = s1.size();
    int len2 = s2.size();
    int len3 = s3.size();

    if(len1 + len2 != len3)
        return false;

    if(len1 == 0 && len2 == 0)
        return len3 == 0;

    if(len1 == 0)
        return s2 == s3;
    if(len2 == 0)
        return s1 == s3;

    return backtrackingCore(s1, s2, s3, 0, 0, 0);
}

int main()
{
    string s1 = "bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa";
    string s2 = "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab";
    string s3 = "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab";

    cout << isInterleave(s1, s2, s3) << "\n";
}