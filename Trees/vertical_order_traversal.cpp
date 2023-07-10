vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> m;
    queue<pair<int, pair<TreeNode *, int>>> q;
    q.push({0, {root, 0}});

    while (!q.empty())
    {
        TreeNode *t = q.front().second.first;
        int cnt = q.front().first;
        int level = q.front().second.second;
        m[cnt][level].insert(t->val);
        q.pop();
        if (t->left != NULL)
            q.push({cnt - 1, {t->left, level + 1}});
        if (t->right != NULL)
            q.push({cnt + 1, {t->right, level + 1}});
    }
    vector<vector<int>> ans;
    for (auto x : m)
    {
        vector<int> temp;
        for (auto y : x.second)
        {
            temp.insert(temp.end(), y.second.begin(), y.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}