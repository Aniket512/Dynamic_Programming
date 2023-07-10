
void levelOrder(TreeNode *root)
{
    if (!root)
        return;
    vector<int> temp;
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            temp.push_back(curr->val);
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        ans.push_back(temp);
        temp.clear();
    }
}
