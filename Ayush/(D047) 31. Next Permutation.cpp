
// TC: o(3n) 
// sc: o(1)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
     int index =-1, n = nums.size();
     // largest prefix match
     for(int i = n-2; i>=0; i--){
        if(nums[i]<nums[i+1]){
            index =i;
            break;
        }
     }   

     // NO break index
     if(index==-1){
        reverse(nums.begin(), nums.end());
        return;
     } 

     // >1 smallest one stay close to prefix match
     for(int i =n-1; i>index; i--){
        if(nums[i]>nums[index]){
            swap(nums[i], nums[index]);
            break;
        }
     }
     // reversing the remaining arry (from break point till last arr) to get sorted arr after smallest prefix match
     reverse(nums.begin()+index+1, nums.end());

    }
};