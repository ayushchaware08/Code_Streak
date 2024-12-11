// TC = O(N)
// SC = O(1)
#include<cmath>
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps =0;
        int l=0, r=0, farthest;
        while(r<nums.size()-1){
            farthest =0;
            // farthest we can reach from curr range(l-r)
            //traverse current window(range) 
            for(int i =l; i<=r; i++){
                farthest = max(i+nums[i], farthest);
            }
            // update for new range
            l=r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};