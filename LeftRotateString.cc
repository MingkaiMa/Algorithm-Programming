#include <iostream>

char* Reverse(char* begin, char* end)
{
    if(begin == NULL || end == NULL)
        return;

    while(begin < end)
    {
        char temp = *begin;
        *begin = *end;
        *end = temp;

        begin++;
        end--;
    }
}

char* LeftRotateString(char* pStr, int n)
{
    if(pStr != NULL)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength > 0 && n > 0 && n < nLength)
        {
            char* firstStart = pStr;
            char* firstEnd = pStr + n - 1;
            char* secondStart = pStr + n;
            char* secondEnd = pStr + nLength - 1;

            Reverse(firstStart, firstEnd);
            Reverse(secondStart, secondEnd);
            Reverse(firstStart, secondEnd);
        }
    }
    
    return pStr;
}