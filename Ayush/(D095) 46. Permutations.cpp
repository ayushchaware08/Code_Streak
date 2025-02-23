// TC: o(n!)
// SC: O(n)
class Solution {
    void solve(vector<int> nums, vector<vector<int>> & ans, int i){
        if(i>=nums.size()){
            ans.push_back(nums); // curr permutation to ans
            return;
        }
        for(int j=i; j<nums.size(); j++){
            swap(nums[i], nums[j]); // put nums[j] at position
            solve(nums, ans, i+1); // resursive fill remaining
            swap(nums[i], nums[j]); // backtrack to bring it to orignal state
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i =0; // position to fill
        solve(nums, ans, i);
        return ans;
    }
};
