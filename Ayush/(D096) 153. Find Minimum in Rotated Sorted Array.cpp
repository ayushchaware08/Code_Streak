// TC: O(log n)
// SC: o(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i =0, j=nums.size()-1;
        while(i<j){
            int mid = (i+j)/2;
            
            // if(nums[mid]>nums[j] && nums[mid]>nums[i]) i = mid+1;
            // else if(nums[mid]<nums[j] && nums[mid]<nums[i]) j = mid-1;
            // // else if(nums[mid]<nums[j] && nums[mid]>nums[i]) return nums[mid];
            // else return nums[mid];

            if(nums[mid]>nums[j]) i = mid+1;
            else j = mid;
        }
        return nums[i];
    }
};