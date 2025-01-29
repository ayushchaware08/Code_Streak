#include <bits/stdc++.h> 
#include<vector>
vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> result;
        TreeNode* curr = root;

        while(curr != nullptr){
            if(curr -> left == nullptr){ // ;eft not exist so go to right
                result.push_back(curr->data);
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
                    result.push_back(curr->data);
                    curr = curr -> left;

                }
                else{
                    // remove the temporary link
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return result;
    }
