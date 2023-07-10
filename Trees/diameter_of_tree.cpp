int ans = 0;
int helper(TreeNode *root)
{
    if (!root)
        return 0;

    int left = helper(root->left);
    int right = helper(root->right);
    ans = max(ans, left + right);
    return max(left, right) + 1;
}
int diameterOfBinaryTree(TreeNode *root)
{
    helper(root);
    return ans;
}