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

int getMinimumDifference(TreeNode *root)
{
    vector<int> arr;
    getInorder(root, arr);
    int ans = INT_MAX;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int d = arr[i + 1] - arr[i];
        ans = min(ans, d);
    }
    return ans;
}

int main()
{
    TreeNode *root = NULL;
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);
    cout << endl;

    cout << getMinimumDifference(root) << endl;
    return 0;
}