// TC: O(2n) -- optimized w/o using hashmap (xor Solution)
// SC: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1, 0);

        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }
        
        for(int i=0; i<=n; i++){
            if(hash[i]==0){
                return i;
            }
        }
        return -1;
    }
};

// n += i - nums[i];