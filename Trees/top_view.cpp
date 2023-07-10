vector<int> topView(Node *root)
{
    map<int, int> m;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *t = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (m.find(cnt) == m.end())
        {
            m[cnt] = t->data;
        }
        if (t->left != NULL)
            q.push({t->left, cnt - 1});
        if (t->right != NULL)
            q.push({t->right, cnt + 1});
    }

    vector<int> ans;
    for (auto x : m)
    {
        ans.push_back(x.second);
    }
    return ans;
}