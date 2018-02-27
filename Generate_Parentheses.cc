#include <iostream>
#include <vector>
#include <string>
using namespace std;



void helper(int left, int right, string s, vector<string>& L)
{
    if(left < 0 || right < 0 || left > right){
        return;
    }

    if(left == 0 && right == 0){
        cout << "***\n";
        cout << s << '\n';
        L.push_back(s);
    }

    else{

        if(left > 0){
            helper(left - 1, right, s + '(', L);
        }

        if(right > 0){
            helper(left, right - 1, s + ')', L);
        }

    }
}

vector<string> generateParentheses(int n){

    vector<string> L;
    helper(n, n, "", L);
    return L;
}


int main(){

    vector<string> R = generateParentheses(3);
    for(int i = 0; i < R.size(); i++){
        cout << R[i] << "\n";
    }
}