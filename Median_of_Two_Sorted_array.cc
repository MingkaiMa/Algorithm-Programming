class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length_total = nums1.size() + nums2.size();

        int i = 0, j = 0;

        vector<int> nums;

        while(i < nums1.size() && j < nums2.size()){

            if(nums1[i] > nums2[j]){
                nums.push_back(nums2[j]);
                j += 1;
            }
            else if(nums1[i] < nums2[j]){
                nums.push_back(nums1[i]);
                i += 1;
            }
            else if(nums1[i] == nums2[j]){
                nums.push_back(nums1[i]);
                nums.push_back(nums1[i]);
                i += 1;
                j += 1;

            }
        }

        if(i == nums1.size() && j == nums2.size()){

            ;
        }
        else if(i == nums1.size()){

            for(j; j < nums2.size(); j++){
                nums.push_back(nums2[j]);
            }
        }
        else if(j == nums2.size()){

            for(i; i < nums1.size(); i++){
                nums.push_back(nums1[i]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            cout << nums[i] << ", ";
        }
        cout << "\n";
        if(nums.size() % 2){

            return nums[nums.size() / 2];
        }else{

            return (nums[nums.size()/ 2] + nums[nums.size() / 2 - 1]) / 2.0;
        }



    }
};