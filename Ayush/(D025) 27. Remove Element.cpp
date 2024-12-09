// Brute force
// TC O(n)
// Sc O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i=0; i<nums.size(); i++){
            if(val != nums[i]){
                nums[index] = nums[i];
                index++;
            }
            // cout<<nums[i];
        }
        // just first k elel= are considerd ignore the next
        return index;
    }
};