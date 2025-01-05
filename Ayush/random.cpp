#include <bits/stdc++.h>
using namespace std;

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

int main(){
    // int n =6;
    vector<int> num={ 1, 1, 1, 2, 2, 3, 2, 3, 3};
    vector<int> ans  = majorityElement(num);
    for(auto it: ans){
        cout<<it<<" ";
    }
    return 0;
}