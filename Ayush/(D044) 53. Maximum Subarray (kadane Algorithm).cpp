// Kadane's Algorithm O(n) TC 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum =0, maxi =INT_MIN;
            for(int i =0; i<nums.size(); i++){
                sum += nums[i];
                maxi = max(maxi, sum);
                if(sum<0) sum =0;
            }
        return maxi;
    }   
};



// O(n^3)  --- TLE

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi =INT_MIN, n=nums.size();
        for(int i =0; i<n; i++){
            for(int j =i; j<n; j++){
                // curr subarr i-j
                int sum =0;
                // to get sum of subarray
                for(int k =i; k<=j; k++){
                    sum += nums[k];
                }
                maxi = max(maxi, sum);
            }
        }
        return maxi;
    }   
};