void inorder(TreeNode *root, vector<int> &ans)
{
    if (root != NULL)
    {
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
}
