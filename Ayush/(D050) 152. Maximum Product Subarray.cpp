// optimal one 
// TC: o(n)
// SC: o(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1, sufix=1;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i=0; i<n;i++){
            // handling 0 case
            if(prefix==0)prefix=1;
            if(sufix==0)sufix=1;
            
            prefix = prefix * nums[i];
            sufix = sufix * nums[n-i-1];
            maxi = max(maxi, max(prefix, sufix));
        }
        return maxi;
    }
};

// Brute force
// TC: o(n^2)
// SC: o(1)
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MAX, prd =1, n=nums.size();
        for(int i =0; i<n; i++){
            for(int j=i; j<n; j++){
                prd = prd*nums[j];
                maxi = max(prd, maxi);
            }
        }
        return maxi;
    }