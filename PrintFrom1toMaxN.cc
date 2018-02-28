#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;

bool Addition(string& s);
void PrintFunc(string& s);
void print1toMax(int n)
{
    if(n <= 0)
    {
        return;
    }

    char* number = new char[n];
    memset(number, '0', n);
    //number[n] = '\0';
    string str(number);

    //cout << str << "\n";

    //return;

    while(!Addition(str))
    {
        PrintFunc(str);
        //cout << str << "\n";
    }

    delete[] number;
}
//
//
//
bool Addition(string& s)
{

    int carry = 0;
    int length = s.size();


    char curr = s[length - 1];
    s[length - 1] = (s[length - 1] - '0' + 1 + carry) % 10 + '0';
    carry = (curr - '0' + 1 + carry) / 10;
//    if(s[length - 1] != '0')
//    {
//        return false;
//    }

    int j = length - 2;
    while(carry == 1)
    {
        char curr = s[j];
        s[j] = (s[j] - '0' + carry) % 10 + '0';
        carry = (curr - '0' + carry) / 10;

        --j;
    }

//    cout << "down\n";
//    cout << s << "\n";
    if(j == -2)
    {
        //cout << "here\n";
        return true;
    }

    return false;
}


void PrintFunc(string& s)
{
    int length = s.size();


    int j = 0;
    while(s[j] == '0')
    {
        j += 1;
    }


    for(int i = j; i < length; i++)
    {
        cout << s[i];
    }

    cout << "\n";


}

void change_string(string& s)
{
    s[0] = 'a';
}


int main()
{
//    std::string s = "happy";
//    change_string(s);
//    std::cout << s << "\n";

    print1toMax(3);

}