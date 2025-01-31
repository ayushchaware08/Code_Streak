// Binary Search
// TC: o(logn)
// SC: o(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high =  nums.size()-2;
        while(low<=high){
            int mid = (low+high)>>1;
            // int mid = (low+high)/2;
            if(nums[mid]==nums[mid^1]){
                // i.e next or previous position check
                low = mid+1;
            }else
            {
                high = mid-1;
            }
        }
        return nums[low];
    }
};

// XOR approch
// TC: o(n)
// SC: o(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans  = nums[0];
        for(int i =1; i<nums.size(); i++){
            ans = ans ^ nums[i];
        }
        return ans;
    }
};