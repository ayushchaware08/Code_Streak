// Using Binary Exponentiation
// TC: O(log n)
// SC: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        double ans =1.0;
        long long power = n;
        // edge case to handle -ve power
        if(power<0) power *= -1;
        while(power){
            if(power%2 == 1){
                ans *= x;
                power--;
            }
            else{ // power%2==0
                x = x*x;
                power = power/2;
            }
        }
        // above edge case
        if(n<0) ans = (double)(1.0) / (double) (ans);
        return ans;
    }
};

// Brute force - ans*=x till n
// TC: O(n)
// SC: O(1)