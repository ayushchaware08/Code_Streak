#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode *InsertNode(TreeNode *root, int key)
{
    if (root == NULL)
    {
        root = new TreeNode(key);
        return root;
    }
    if (root->data > key)
    {
        root->left = InsertNode(root->left, key);
    }
    else
    {
        root->right = InsertNode(root->right, key);
    }
    return root;
}
TreeNode *buildTree(TreeNode *root)
{
    int data;
    cout << "enter root" << endl;
    cin >> data;
    root = new TreeNode(data);
    do
    {
        cout << "Enter number: ";
        cin >> data;
        if (data == -1)
        {
            break;
        }
        root = InsertNode(root, data);
    } while (1);
    return root;
}
void InOrder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout << root->data << ' ';
    InOrder(root->right);
}
