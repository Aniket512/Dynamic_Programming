bool ans = 1;
int helper(TreeNode *root)
{
    if (!root)
        return 0;

    int l = helper(root->left);
    int r = helper(root->right);

    if (abs(l - r) > 1)
    {
        ans = 0;
    }
    return max(l, r) + 1;
}
bool isBalanced(TreeNode *root)
{
    helper(root);
    return ans;
}
