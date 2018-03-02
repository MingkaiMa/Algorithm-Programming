#include <iostream>
using namespace std;

void swap(char* p1, char* p2)
{
    char temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void Permute(char* str, char* begin)
{
    cout << "\n----\n";
    cout << str << "\n";
    cout << "----\n\n";

    if(*begin == '\0')
    {
        cout << str << "\n";
    }
    else
    {
        for(char* ch = begin; *ch != '\0'; ++ch)
        {
            cout << "swap for:\n";
            cout << *ch << ", " << *begin<< "\n";
            swap(ch, begin);
            Permute(str, begin + 1);
            swap(ch, begin);
        }
    }
}

void Permutation(char* str)
{
    if(str == NULL)
        return;

    Permute(str, str);
}


int main()
{
    char s[] = "abc";
    Permutation(s);
}