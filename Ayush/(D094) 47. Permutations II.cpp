// TC: o(n!*n)
// SC: o(n)
class Solution {
public:

void genPermutation(int i, vector<int> &nums, vector<bool> &used, vector<int> &curr, vector<vector<int>>& result) {
    if (i == nums.size()) {
        result.push_back(curr);
        return;
    }
    unordered_set<int> usedInPosition;
    for (int j = 0; j < nums.size(); j++) {
        if (used[j] || usedInPosition.count(nums[j])) continue;
        usedInPosition.insert(nums[j]); // marked to be used in this position
        used[j] = true; // marked true
        curr.push_back(nums[j]);
        genPermutation(i + 1, nums, used, curr,result); // next char
        used[j] = false; // unmark char using backtrack
        curr.pop_back();
        
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false); // check char if used
        vector<int> curr;
        genPermutation(0, nums, used, curr, result);
        return result;
    }
};

 