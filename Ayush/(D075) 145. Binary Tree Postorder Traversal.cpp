// TC o(n)
// sc o(n)
class Solution {
public:
    void postorder(TreeNode* root, vector<int> & arr){
        // base case
        if(root == NULL){
            return;
        }
        else{
            postorder(root->left, arr); // Left
            postorder(root -> right, arr); // Right
            arr.push_back(root->val); // Node
        }
    }   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postorder(root,arr);
        return arr;
    
        
    }
};