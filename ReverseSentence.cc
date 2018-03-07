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

char* ReverseSentence(char* data)
{
    if(data == NULL)
        return NULL;

    char* begin = data;
    char* end = data;
    while(*end != '\0')
        end++;

    end--;

    Reverse(begin, end);

    begin = data;
    end = data;

    while(*begin != '\0')
    {
        if(*begin == '')
        {
            begin++;
            end++;
        }
        else if(*end == '' || *end == '\0')
        {
            Reverse(begin, --end);
            begin = ++end;
        }
        else
            end++;
    }
    return data;
}