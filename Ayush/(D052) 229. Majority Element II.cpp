// more optimized
// TC: o(n+n)
// SC: o(1)

// optimal using map
// TC: o(nlogn)
// SC: o(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        map<int, int> mapp;
        int mini = int(n/3)+1;

        for(int i =0; i<n; i++){
            mapp[nums[i]]++;
            if(mapp[nums[i]]==mini) ans.push_back(nums[i]);
            // optimization
            if(ans.size()==2) break;
        }     
        return ans;
    }   

};

// BRute force
// TC: o(n*n)
// SC: o(1)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size(), cnt;
        for(int i =0; i<n;i++){
            if(ans.size()==0 || ans[0]!=nums[i]){
                cnt =0; 
                for(int j =0; j<n; j++){
                    if(nums[j]==nums[i]) cnt++;
                }
                if(cnt>(n/3)) ans.push_back(nums[i]);
            }
            if(ans.size()==2) break;
        }
        return ans;
    }
};