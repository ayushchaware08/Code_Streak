// Binary Search
// TC: O(n*logm)
// SC: O(1)

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            int operations = 0;
            for (int n : nums) 
                
                if ((operations += (n - 1) / mid) > maxOperations) break;
            if(operations <= maxOperations){
                high = mid;
            }
            else low = mid + 1;
        }
        return high;
    }
};