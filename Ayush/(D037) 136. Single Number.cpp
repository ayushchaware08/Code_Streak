// APPROACH Using XOR
// TC: O(n)
// SC: O(1)
class Solution{
public:
    int singleNumber(vector<int>& nums){
        int ans =0;
        for(auto a: nums){
            ans^=a;
        }
        return ans;
    }
};

// APPROACH Using Map
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        // store cnt
        for(auto a: nums) map[a]++;

        for(auto a: map){
            if(a.second==1) return a.first;
        }
        return -1;
    }
};