void makeParent(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &m)
{
  if (root->left != NULL)
  {
    m[root->left] = root;
    makeParent(root->left, m);
  }
  if (root->right != NULL)
  {
    m[root->right] = root;
    makeParent(root->right, m);
  }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
  unordered_map<TreeNode *, TreeNode *> m;
  makeParent(root, m);
  queue<pair<TreeNode *, int>> q;
  q.push({target, 0});
  int i = 0;
  unordered_map<TreeNode *, int> vis;
  vis[target] = 1;
  while (!q.empty())
  {
    if (i == k)
      break;
    int cnt = q.size();
    for (int i = 0; i < cnt; i++)
    {
      TreeNode *t = q.front().first;
      int dep = q.front().second;
      q.pop();

      if (t->left && !vis[t->left])
      {
        vis[t->left] = 1;
        q.push({t->left, dep + 1});
      }
      if (t->right && !vis[t->right])
      {
        vis[t->right] = 1;
        q.push({t->right, dep + 1});
      }
      if (m[t] && !vis[m[t]])
      {
        vis[m[t]] = 1;
        q.push({m[t], dep + 1});
      }
    }
    i++;
  }
  vector<int> ans;
  while (!q.empty())
  {
    ans.push_back(q.front().first->val);
    q.pop();
  }
  return ans;
}
