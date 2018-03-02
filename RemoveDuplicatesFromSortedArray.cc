#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1)
            return nums.size();

        int curr = nums[0];
        int newLength = 1;

        int i = 1;
        while(i < nums.size())
        {
            if(curr != nums[i])
            {
                newLength++;
                curr = nums[i];
                i++;
                continue;
            }

            nums.erase(nums.begin() + i);

        }


        return newLength;
    }
};

int main()
{
    vector<int> L = {1, 1, 2, 2, 3};

    for(int i = 0; i < L.size(); i++)
    {
        cout << L[i] << ", ";
    }
    cout << "\n";


    int curr = L[0];

    int i = 1;
    while(i < L.size())
    {
        if(curr != L[i])
        {
            curr = L[i];
            ++i;
            continue;
        }

        if(curr == L[i])
        {
            L.erase(L.begin() + i);
        }
    }


    int j = 0;
    for(; j < L.size(); j++)
    {
        cout << L[j] << ", ";
    }
    cout << "\n";
    cout << j << "\n";
    cout << "\n";

}