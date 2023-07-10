vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    stack<TreeNode *> s;
    TreeNode *temp = root;

    while (temp || !s.empty())
    {
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }

        temp = s.top();
        s.pop();
        ans.push_back(temp->val);
        temp = temp->right;
    }

    return ans;
}
