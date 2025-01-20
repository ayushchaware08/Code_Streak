// only optimal one
// O(n) O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt =0,maxi=0;
        for(int i =0;i<nums.size();i++){
            if(nums[i] ==1){
                cnt++;
                maxi = max(maxi, cnt);
            }
            else cnt=0;
        }   
        return maxi;
    }
};