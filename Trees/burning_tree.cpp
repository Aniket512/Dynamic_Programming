void makeParent(Node *root, unordered_map<Node *, Node *> &m)
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
Node *findTarget(Node *root, int target)
{
  if (!root || root->data == target)
    return root;
  Node *left = findTarget(root->left, target);
  Node *right = findTarget(root->right, target);
  if (left)
    return left;
  else
    return right;
}

int minTime(Node *root, int target)
{
  unordered_map<Node *, Node *> m;
  makeParent(root, m);
  queue<pair<Node *, int>> q;
  Node *targetNode = findTarget(root, target);
  q.push({targetNode, 0});
  unordered_map<Node *, int> vis;
  vis[targetNode] = 1;
  int ans = 0;
  while (!q.empty())
  {
    int cnt = q.size();
    for (int i = 0; i < cnt; i++)
    {
      Node *t = q.front().first;
      int dep = q.front().second;
      ans = max(dep, ans);
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
  }
  return ans;
}