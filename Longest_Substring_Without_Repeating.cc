#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//
//        if(s == ""){
//            return 0;
//        }
//
//        int n = s.length();
//        int curr_len = 1;
//        int max_len = 1;
//        int pre_index;
//        int i;
//        int* visited = new int[256];
//
//        for(i = 0; i < 256; i++){
//            visited[i] = -1;
//        }
//
//        visited[s[0]] = 0;
//
//        for(i = 1; i < n; i++){
//
//            pre_index = visited[s[i]];
//            if(pre_index == -1 || i - curr_len > pre_index){
//                curr_len += 1;
//            }
//            else{
//
//                if(curr_len > max_len){
//                    max_len = curr_len;
//                }
//                curr_len = i - pre_index;
//            }
//
//            visited[s[i]] = i;
//        }
//
//        if(curr_len > max_len){
//            max_len = curr_len;
//        }
//
//        delete[] visited;
//        return max_len;
//    }
//};





//solution 2

int lengthOfLongestSubstring(string s){

    int n = s.length();
    int ans = 0;
    int* index = new int[128];

    for(int k = 0; k < 128; k++){
        index[k] = 0;
    }

    for(int j = 0, i = 0; j < n; j++){

        i = max(index[s[j]], i);
        ans = max(ans, j - i + 1);
        index[s[j]] = j + 1;
    }

    return ans;
}

int main(){

    string s = "abcdeab";
    cout<< lengthOfLongestSubstring(s) << "\n";
}













