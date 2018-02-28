#include <iostream>

bool matchAid(char* str, char* pattern);
bool regex_match(char* str, char* pattern)
{
    if(str == NULL || pattern == NULL)
    {
        return false;
    }

    return matchAid(str, pattern);
}


bool matchAid(char* str, char* pattern)
{
    if(*str == '\0' && *pattern == '\0')
    {
        return true;
    }

    if(*str != '\0' && *pattern == '\0')
    {
        return false;
    }

    if(*(pattern+ 1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            return matchAid(str + 1, pattern + 2) || matchAid(str + 1, pattern) || matchAid(str, pattern + 2);

        else
            return matchAid(str, pattern + 2);
    }


    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchAid(str + 1, pattern + 1);

    return false;
}


int main()
{

    char str[] = "aaa";
    char pattern[] = "ab*a";

    std::cout << regex_match(str, pattern) << "\n";


}