// moris Traverseal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* curr = root;

        while(curr != nullptr){
            if(curr -> left == nullptr){ // ;eft not exist so go to right
                result.push_back(curr->val);
                curr = curr->right;

            }
            else{
                // find predessor
                TreeNode* prev = curr -> left;
                while(prev ->right!=nullptr && prev->right != curr){ // to extreme right
                    prev = prev -> right;
                }
                // update curr (temperory linkto curr)
                if(prev->right == nullptr){
                    prev -> right = curr;
                    curr = curr -> left;

                }
                else{
                    // remove the temporary link
                    prev->right = nullptr;
                    result.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};

// TC o(n)
// SC O(n)
class Solution {
public:
    void inorder(TreeNode* root,vector<int>& arr){
        
        // base case
        if(root == nullptr){
            return;
        }
        else{
            inorder(root->left, arr); // Left
            arr.push_back(root->val); // Node
            inorder(root -> right,arr); // Right
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return arr;
    }
};