// optimal two pointer
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        // l r end up at largest 
        int lmax=0, rmax=0, total=0;
        int l=0, r=height.size()-1;
        while(l<r){
            if(height[l]<=height[r]){ 
                if(lmax>height[l]){ // can trap water here
                    total+= lmax-height[l];
                }
                else{ 
                    // update lmax to curr height
                    lmax = height[l];

                }
                l++;
            }
            else{
                if(rmax>height[r]){ // can trap water here
                    total+= rmax -height[r];
                }
                else{
                    // update rmax to curr height
                    rmax = height[r];
                }
                r--;
            }
        }
        return total;
    }
};