// TC: O(n)
// SC: o(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = -1, second =-1;
        for(int i =0; i<n;i++){
            if(nums[i]==target){
            first = i;
            int j =i;
                while( j<n && nums[j]==target){
                    second = j;
                    j++;
                }
                break;
            }
        }
        if(second==-1) first =-1;
        return {first,second};

    }
};