vector<int> leftView(Node *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    int cnt = q.size();
    for (int i = 0; i < cnt; i++)
    {
      Node *t = q.front();
      q.pop();

      if (i == 0)
        ans.push_back(t->data);
      if (t->left != NULL)
        q.push(t->left);
      if (t->right != NULL)
        q.push(t->right);
    }
  }
  return ans;
}
