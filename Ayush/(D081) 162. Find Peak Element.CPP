class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        for(int i =0; i<nums.size()-1; i++){
            if(nums[i+1]<nums[i]) return i;
        }
        return nums.size()-1;
    }
};