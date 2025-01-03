#include "Node.cpp"

void getInorder(TreeNode *root, vector<int> &arr)
{
    if (root == NULL)
    {
        return;
    }
    getInorder(root->left, arr);
    arr.push_back(root->data);
    getInorder(root->right, arr);
}

int kthLargest(TreeNode *root, int k)
{
    vector<int> arr;
    getInorder(root, arr);
    return arr[arr.size() - k];
}

int solve(TreeNode *root, int &i, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    int right = solve(root->right, i, k);
    if (right != -1)
    {
        return right;
    }
    i++;
    if (i == k)
    {
        return root->data;
    }
    return solve(root->left, i, k);
}

int kthLargest1(TreeNode *root, int k)
{
    int i = 0;
    return solve(root, i, k);
}

int main()
{
    TreeNode *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    int k = 2;
    cout << kthLargest(root, k) << endl;
    cout << kthLargest1(root, k) << endl;

    return 0;
}
