// TC: O(n)
// SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt =0;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                if(cnt>=1) // exceed cnt of 2
                    nums.erase(nums.begin()+i--);
                else cnt++;
            }
            else cnt =0;
        }
        return nums.size();
    }
};


// TC: O(n)
// SC: O(1)
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k =2;
        if(nums.size()<=2) return nums.size();
        for(int i=2; i<nums.size(); i++){
            // if(nums[i] != nums[i-2]){
            if(nums[i] != nums[k-2]){
                nums[k]=nums[i];
                k++;
            }
        }
        return k;
    }
};