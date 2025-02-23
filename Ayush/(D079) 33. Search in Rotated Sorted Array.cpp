// Binary Search - Optimal one
// TC: o(logn)
// SC: o(1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low=0, high = n-1;
        while (low <= high) {
            int mid = (low+high) / 2;

            if (nums[mid] == target) return mid;

            //left sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) { // exist
                    high=mid-1;
                }
                else low=mid+1;
            }
            // right Sorted
            else {
                if (nums[mid]<=target && target<=nums[high]) {// exists
                    low=mid+1;
                }
                else high=mid 1;
            }
        }
        return -1;
    }
};

// brute force
// TC: o(n)
// SC: (1)
class Solution {
public:
    int search(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target) return i;
        }
        return -1;
    }
};