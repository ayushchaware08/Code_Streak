// O(n^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt =0,  n= nums.size();
        for(int i =0; i<n; i++){
            int sum=0;
            for(int j =i; j<n; j++){
                sum += nums[j];
                if(sum == k){
                    cnt++;
                    // break;
                }
            }
        }
        return cnt;
    }
};