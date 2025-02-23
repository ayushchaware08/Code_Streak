// TC; o(log5_n)
class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        // count number of multiple of 5;
        while(n>0){
            // eg 5! 100!
            n = n/5; // 1 20->4
            ans = ans + n;
        }
        return ans;
    }
};