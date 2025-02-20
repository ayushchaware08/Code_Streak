// https://leetcode.com/problems/kth-largest-element-in-an-array/description/?envType=study-plan-v2&envId=top-interview-150

// without sorting - Divide and conquer (pivot)
// O(n^2)
class Solution {
public:
    int partition(vector<int>& nums,  int left, int right){
        int pivot =nums[left];
        int l = left+1; // starting index of left
        int r = right; // starting index of right
        while(l<=r){
            if(nums[l]<pivot && nums[r]>pivot){
                swap(nums[l], nums[r]);
                l++;
                r--;
            }
            if(nums[l]>=pivot) l++;
            if(nums[r]<=pivot) r--;
        }
        swap(nums[r], nums[left]); // final sorted position
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left =0, right=nums.size()-1, kEle;
        while(1){ // infinite loop 
            int index = partition(nums, left, right);
            if(index == k-1){
                kEle= nums[index];
                break;
            }
            if(index<k-1) left = index+1;
            else right = index-1;
        }
        return kEle;
    }
};


// try heap


// O(nlogn) - using sorting
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};