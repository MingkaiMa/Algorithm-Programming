#include <iostream>
#include <string>
using namespace std;



string longestPalSubstr(string s){


    int n = s.length();

    bool table[n][n];
    memset(table, 0, sizeof(table));

    int maxLength = 1;
    for(int i = 0; i < n; i++){
        table[i][i] = true;
    }

    cout << "All substrings of length 1 are palindromes\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << table[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";



    int start = 0;

    for(int i = 0; i < n - 1; i++){

        if(s[i] == s[i + 1]){
            table[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }

    cout << "substring of length 2\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << table[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";



    for(int k = 3; k <= n; k++){
        for(int i = 0; i < n - k + 1; i++){
            int j = i + k - 1;

            if(table[i + 1][j - 1] && s[i] == s[j]){
                table[i][j] = true;
                if(k > maxLength){
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    cout << "final \n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << table[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "start is: " << start << " max length is: " << maxLength << "\n";


    string r;
    for(int i = start; i <= start + maxLength - 1; i++){
        r += s[i];
    }
    return r;
}

int main(){

    string str = "abab";
    cout << longestPalSubstr(str) << "\n";

}