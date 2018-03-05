#include <iostream>
using namespace std;


//solution: only contains a-z
char FirstNoRepeating(char* str)
{


    if(str == NULL)
    {
        return 'N';
    }

    int lengthStr = 0;

    char* countLength = str;

    while(*countLength != '\0')
    {
        lengthStr++;
        countLength++;
    }

    if(lengthStr == 1)
    {
        return str[0];
    }

    //cout << lengthStr << "\n";

    int* countArray = new int[26];

    for(int i = 0; i < 26; i++)
        countArray[i] = 0;

    for(int i = 0; i < lengthStr; i++)
    {
        countArray[str[i] - 'a']++;
    }

    int res = -1;
    for(int i = 0; i < 26; i++)
    {
        //cout << countArray[i] << ", ";
        if(countArray[i] == 1)
        {
            res = i;
            break;
        }
    }
    //cout << "\n";

    if(res == -1)
    {
        return 'N';
    }

    return 'a' + res;

}



solution: contains 256 all ascii
char FirstNotRepeating(char* pString)
{
    if(pString == NULL)
    {
        return '\0';
    }

    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i = 0; i < 256; i++)
        hashTable[i] = 0;


    char* pHashKey = pString;
    while(*pHashKey != '\0')
        hashTable[*(pHashKey++)]++;


    pHashKey = pString;
    while(*pHashKey != '\0')
    {
        if(hashTable[*pHashKey] == 1)
        {
            return *pHashKey;
        }

        pHashKey++;
    }

    return '\0';
}




int main()
{
    char str[] = "aaaaa";
    cout << FirstNoRepeating(str) << "\n";
}