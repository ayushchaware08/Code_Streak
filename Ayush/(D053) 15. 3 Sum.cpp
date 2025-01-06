// optimal one
// TC: O(nlogn + n^2)
// SC: O(m) - m is no of unique triplets
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        
        for(int i =0; i<n; i++){
            // skip duplicates (to avoid duplicates) and out of bound issue
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum<0) j++; // too small
                else if(sum>0) k--; // too large
                else{ // required
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // skip duplicates(to avoid duplicates) and out of bound iisue
                    while(j<k && nums[j] == nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--;

                }
            }
        }
            
        return ans;
    }
};

// Better one - hashing and 2 ptr
// TC: O(n^2 logm)
// SC: O(n+m)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(); 
        set<vector<int>> list;
        for(int i =0; i<n; i++){
            set<int> hash;
            for(int j =i+1; j<n; j++){
                int third = -(nums[i]+nums[j]);
                if(hash.find(third) != hash.end()){
                    vector<int> temp = { nums[i], nums[j], third};
                    // to maintain uniqueness
                    sort(temp.begin(),temp.end());
                    list.insert(temp);
                }
                hash.insert(nums[j]);
                }
            }
        vector<vector<int>> ans(list.begin(), list.end());
        return ans;
    }
};

// Brute Force Solution- 3 pointer
// TC: O(n^3 logm)
// SC: 2 O(m)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> list;
        for(int i =0; i<n; i++){
            for(int j =i+1; j<n; j++){
                for(int k = j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp = {nums[i],nums[j], nums[k]};
                        // to ensure uniqueness
                        sort(temp.begin(), temp.end());
                        list.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(list.begin(), list.end());
        return ans;
    }
};