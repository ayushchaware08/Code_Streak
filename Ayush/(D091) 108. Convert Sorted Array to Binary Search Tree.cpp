/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// TC: o(nllogn)
// SC: o(n);
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return new TreeNode(nums[0]);

        int mid = n/2;
        // root
        TreeNode* root = new TreeNode(nums[mid]);

        // left and right
        vector<int> left(nums.begin(), nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1, nums.end());
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);

        return root;
    }
};


// optimization can be through creating helper function(nums, left, right) so, SC:o(logn) TC:o(n)