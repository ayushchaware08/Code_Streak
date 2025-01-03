#include "Node.cpp"

bool solve(TreeNode *root, int min, int max)
{
    if (root == NULL)
    {
        return 1;
    }

    if (root->data > min && root->data < max)
    {
        bool left = solve(root->left, min, root->data);
        bool right = solve(root->right, root->data, max);

        return (left & right);
    }
    else
    {
        return 0;
    }
}

bool isValid1(TreeNode *root)
{
    int min = INT_MIN;
    int max = INT_MAX;
    return solve(root, min, max);
}

int main()
{
    TreeNode *root = NULL;
    // root = buildTree1(root);
    // 1 2  3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
    root = buildTree(root);
    // 5 2 1 3 6 9 7 -1
    cout << "Here is tree" << endl;
    InOrder(root);

    cout << isValid1(root) << endl;
    return 0;
}
