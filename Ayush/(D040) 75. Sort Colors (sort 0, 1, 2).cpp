// TC: o(3n)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int pos =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
        for(int i = pos; i<nums.size(); i++){
            if(nums[i]==1){
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
        for(int i = pos; i<nums.size(); i++){
            if(nums[i]==1){
                swap(nums[pos], nums[i]);
                pos++;
            }
        }
        
    }
};

// TC O(n)
// SC O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0, w=0, b=nums.size()-1;
        
        while(w<=b){
            // red one adj 0->r=0
            if(nums[w]==0){
                swap(nums[w],nums[r]);
                r++;
                w++;
            }
            // white postion adj r->w =1
            else if(nums[w]==1){
                w++;
            }
            // blue b->n=2
            else{
                swap(nums[w],nums[b]);
                b--;
            }
        }
    }
};