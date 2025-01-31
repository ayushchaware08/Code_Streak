// TC: o(n)
// SC: o(1)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l =0, r=height.size()-1;
        int maxarea = 0;
        
        while(l<r){
            int currarea = min(height[l], height[r]) * (r-l);
            maxarea = max(currarea, maxarea);

            // to handle the pointer to maintain container size;
            if(height[l]<height[r]){
                l++;
            }else r--;

        }
        return maxarea;
    }
};