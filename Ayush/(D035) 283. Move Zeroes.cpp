// TC: O(n)
// SC: O(1)
// r look for non zero ele and put at l
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for(int r=0; r<nums.size();r++){
            if(nums[r]!=0){
                swap(nums[l],nums[r]);
                l++;
            }
        }
    }
};