// LinkedList Cycle Method - optimal
// TC: O(n);
// SC: O(1);


// Hashing approach - Having a frequency array
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n,0);
        for(int i =0; i<n; i++){
            if(freq[nums[i]] == 0) freq[nums[i]]+=1;
            else return nums[i];
        }
        return 0;
    }
};

// Navie Approach Using sorting
// TC: O(nlogn + n)
// SC: O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i =1; i<n; i++){
            if(nums[i]==nums[i-1]) return nums[i];
        }
        return -1;
    }
};