#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
    Approach #1
    word_by_word
    https://www.geeksforgeeks.org/longest-common-prefix-set-1-word-by-word-matching/
*/
string findLCP(string s1, string s2){

    string r;
    for(int i = 0; i < s1.size() && i < s2.size(); i++){

        if(s1[i] == s2[i]){
            r += s1[i];
        }else{
            break;
        }
    }
    return r;
}

string findLCPamongStrings(vector<string>& strs){

    string r = findLCP(strs[0], strs[1]);


    for(int i = 2; i < strs.size(); i++){
        r = findLCP(r, strs[i]);
    }

    return r;
}


/*
    Approach #2
    char_by_char
    https://www.geeksforgeeks.org/longest-common-prefix-set-2-character-by-character-matching/
*/

int minLength(vector<string>& strs){

    int min_len = strs[0].length();

    for(int i = 0; i < strs.size(); i++){
        if(min_len > strs[i].length()){
            min_len = strs[i].length();
        }
    }
    return min_len;
}

string LongestCommonPrefix(vector<string>& strs){

    int min_len = minLength(strs);

    char curr;
    string r;
    for(int i = 0; i < min_len; i++){

        curr = strs[0][i];
        for(int j = 1; j < strs.size(); j++){

            if(curr != strs[j][i]){
                return r;
            }
        }

        r += curr;
    }


    return r;
}





int main(){

//    string s1 = "abcdef123";
//    string s2 = "abcggg";
//    string r = findLCP(s1, s2);
//    cout << r<< "\n";

    vector<string> strs = {"ab", "abce", "a"};
    string r = LongestCommonPrefix(strs);
    cout << r << "\n";


}