#include <iostream>
#include <string>
using namespace std;

int LongestSubstringWithoutDuplication(const string& str)
{
    int currLength = 0;
    int maxLength = 0;

    int* position = new int[26];

    for(int i = 0; i < 26; i++)
    {
        position[i] = -1;
    }

    for(int i = 0; i < str.length(); i++)
    {
        int preIndex = position[str[i] - 'a'];

        if(preIndex < 0 || i - preIndex > currLength)
        {
            ++currLength;
        }
        else
        {
            if(currLength > maxLength)
                maxLength = currLength;

            currLength = i - preIndex;
        }

        position[str[i] - 'a'] = i;
    }

    if(currLength > maxLength)
        maxLength = currLength;

    delete[] position;

    return maxLength;
}