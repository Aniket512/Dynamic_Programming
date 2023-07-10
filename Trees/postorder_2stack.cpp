vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> s1;
    stack<int> s2;
    s1.push(root);
    while (!s1.empty())
    {
        auto t = s1.top();
        s1.pop();
        s2.push(t->val);

        if (t->left)
            s1.push(t->left);
        if (t->right)
            s1.push(t->right);
    }
    while (!s2.empty())
    {
        ans.push_back(s2.top());
        s2.pop();
    }
    return ans;
}