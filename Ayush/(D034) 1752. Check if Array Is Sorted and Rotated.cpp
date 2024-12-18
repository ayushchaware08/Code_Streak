// TC: O(n)
// SC: O(1)

class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt =0, n=nums.size();
        /// that one aowest to highest pnt
        for(int i =1; i<n; i++){
            if(nums[i-1]>nums[i]){
                cnt++;
            }
        }
        if(nums[0]<nums[n-1]) cnt++;
        return cnt<=1;
    }
};