// Moore's Voting Algorithm
// TC : o(n)
// SC : o(1)


// hashmap approch
// TC : O(n)
// sc : O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m; // ele, freq

        for(int i = 0; i<n; i++){
            m[nums[i]]++; // count freq of each ele
        }
        n =n/2; // threshold
        for(auto x: m){ // iterate through map
            if(x.second > n){
                return x.first;
            }
        }
        return 0; // not found
    }
};

// Approach: Sorting
// TC = O(n logn) since sorting array
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};
