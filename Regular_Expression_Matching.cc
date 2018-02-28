#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main(){

    regex pattern("a");

    string s = "aa";

    if(regex_match(s, pattern)){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }


}