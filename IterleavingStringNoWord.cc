class Solution {
public:
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
        
        
        string::iterator p1 = s1.begin();
        string::iterator p2 = s2.begin();
        string::iterator p3 = s3.begin();
        
        bool res = true;
        
        while(true)
        {
            
            if(p3 == s3.end())
            {
                res = true;
                break;
            }
            
            if(*p1 == *p3)
            {
                while(p1 != s1.end() && *p1 == *p3)
                {
                    p1++;
                    p3++;
                    if(p1 == s1.end())
                        break;
                }
            }
            
            else if(p2 != s2.end() && *p2 == *p3)
            {
                while(*p2 == *p3)
                {
                    p2++;
                    p3++;
                    if(p2 == s2.end())
                        break;
                }
            }
            
            else
            {
                res = false;
                break;
            }
            
        }
        
        return res;
    }
};
