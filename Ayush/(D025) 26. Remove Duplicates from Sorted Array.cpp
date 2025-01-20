// optimal - two pointer
// TC: o(n)
// sC: o(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =1;
        for(int i =1; i<nums.size(); i++){
             // compare it with prv one not the precedding one
            if(nums[i] != nums[i-1]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};

// Brute Force - Use Hashset
// TC: 
// SC: 