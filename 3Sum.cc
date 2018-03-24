#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool func(int& a, int &b){
    return a < b;
}
vector<vector<int>> threeSum(vector<int>& nums){


    vector<vector<int>> R;

    vector<int> L;
    int skip_flag = 0;

    sort(nums.begin(), nums.end(), func);




    int left, right;

    for(int i = 0; i < nums.size() - 2; i++){

        skip_flag = 0;

        for(int k = 0; k < L.size(); k++){
            if(L[k] == nums[i]){
                skip_flag = 1;
                break;
            }
        }

        if(skip_flag == 1){
            continue;
        }

        cout << "here i: " << nums[i] << "\n";
        L.push_back(nums[i]);

        left = i + 1;
        right = nums.size() - 1;

        while(left < right){

            if(nums[i] + nums[left] + nums[right] == 0){
                vector<int> r = {nums[i], nums[left], nums[right]};
                R.push_back(r);
                while(left < right && nums[left] == nums[left + 1])
                {
                    left += 1;
                }
                while(left < right && nums[right] == nums[right - 1])
                {
                    right -= 1;
                }
                left += 1;
                right -= 1;
            }
            else if(nums[i] + nums[left] + nums[right] < 0){
                left += 1;
            }
            else{
                right -= 1;
            }


        }

    }

    return R;
}


int main(){

    vector<int> L = {-2, 0, 0, 2, 2};
//    set<int> S(L.begin(), L.end());
//
//    L.assign(S.begin(), S.end());
//    for(int i = 0; i < L.size(); i++){
//
//        cout << L[i] << ", ";
//
//    }
//    cout << "\n";


    vector<vector<int>> R = threeSum(L);
    for(int i = 0; i < R.size(); i++){

        for(int j = 0; j < R[i].size(); j++){

            cout << R[i][j] << ", ";

        }
        cout << "\n";
    }

    cout << "\n";
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
