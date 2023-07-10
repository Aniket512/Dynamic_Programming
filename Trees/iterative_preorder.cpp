vector<int> preorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty())
    {
        TreeNode *t = s.top();
        ans.push_back(t->val);
        s.pop();
        if (t->left != NULL)
            s.push(t->left);
        if (t->right != NULL)
            s.push(t->right);
    }
    return ans;
}