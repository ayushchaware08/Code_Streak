// TC O(n)
// SC o(n)
class Solution {
public:
    void preorder(TreeNode* root, vector<int> & arr){
        // base case
        if(root == NULL){
            return;
        }
        else{
            arr.push_back(root->val); // Node
            preorder(root->left, arr); // Left
            preorder(root -> right, arr); // Right
        }
    }   
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root,arr);
        return arr;
    }
};