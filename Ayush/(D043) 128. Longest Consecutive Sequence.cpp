class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums.size()==0) return 0;

        int longest =1, cnt=0, lastSmallest=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            // inc to curr seq
            if(nums[i]-1==lastSmallest){
                cnt = cnt+1;
                lastSmallest = nums[i];
            }
            // new sequence
            else if(nums[i]!=lastSmallest){
                cnt =1;
                lastSmallest= nums[i];
            }
            longest = max(longest, cnt);
        }
        return longest;
    }
};