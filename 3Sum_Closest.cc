#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
bool func(int& a, int &b){
    return a < b;
}

int threeSum(vector<int>& nums, int target){








    sort(nums.begin(), nums.end(), func);

    int left, right;
    int R;
    int min_diff = 10000000;

    for(int i = 0; i < nums.size() - 2; i++){


        left = i + 1;
        right = nums.size() - 1;

        while(left < right){

            int sum = nums[i] + nums[left] + nums[right];
            if(sum < target){

                if(target - sum < min_diff)
                {
                    min_diff = target - sum;
                    R = sum;
                }
                left += 1;

                //right -= 1;
            }
            else if(sum > target){
                if(sum - target < min_diff){
                    min_diff = sum - target;
                    R = sum;
                }
                right -= 1;
            }
            else{
                return sum;
            }


        }

    }

    return R;
}


int main(){

    vector<int> L = {1, 1, -1, -1, 3};
//    set<int> S(L.begin(), L.end());
//
//    L.assign(S.begin(), S.end());
//    for(int i = 0; i < L.size(); i++){
//
//        cout << L[i] << ", ";
//
//    }
//    cout << "\n";

    //cout<< INI_MAX << "\n";

    int R = threeSum(L, 1);


    cout << R << "\n";
}