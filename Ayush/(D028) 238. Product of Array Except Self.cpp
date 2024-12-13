// Better approach
// TC: o(N)
// SC: O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1); //
        // first prefix mul then suffix mul
        // forward loop for prefix mul
        for(int prefix =1; prefix<n; prefix++){
            ans[prefix] = ans[prefix-1] * nums[prefix-1];
        }
        // backward loop for suffix mul
        int suffix=1;
        for(int i=n-2; i>=0; i--){
            suffix *= nums[i+1];
            ans[i] *= suffix;
        }
        return ans;
    }
};

// Brute Force AC
// TC: O(n^2)
// TLE as constrains 10^5 and n^2 code never exceptd in this
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j){
                    ans[i] *= nums[j];
                }
            }
        }
        return ans;
    }
};