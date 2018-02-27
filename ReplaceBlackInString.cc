#include <iostream>


void ReplaceBlackinString(char s[], int length)
{
    if(s == NULL || length <= 0)
    {
        return;
    }


    int length_begin = 0;
    int nb_black = 0;
    int i = 0;
    while(s[i] != '\0')
    {
        length_begin += 1;
        if(s[i] == ' ')
        {
            nb_black += 1;
        }

        i += 1;
    }


    int length_new = length_begin + 2 * nb_black;
    if(length_new > length)
    {
        return;
    }

    int p1 = length_begin;
    int p2 = length_new;

    while(p1 >=0 && p2 > p1)
    {
        if(s[p1] == ' ')
        {
            s[p2--] = '0';
            s[p2--] = '2';
            s[p2--] = '%';
        }
        else
        {
            s[p2--] = s[p1];
        }
        --p1;
    }
}

int main()
{
    char s[19] = "we are happy.";


    ReplaceBlackinString(s, 19);
    //int count = 0;
    int i = 0;

    while(s[i] != '\0')
    {
        std::cout << s[i];
        i++;

    }
    std::cout << "\n";

    //std::cout << count << "\n";


}