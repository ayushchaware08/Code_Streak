// TC: o(n)
// SC: o(min(n,k))
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(int i =0; i<nums.size(); i++){
            // seen the index before
            if(mpp.count(nums[i])){
                if(abs(i- mpp[nums[i]])<=k) return true;
            }
            // not seen the index
            mpp[nums[i]] = i;
        }
        // not found the pair
        return false;
    }
};