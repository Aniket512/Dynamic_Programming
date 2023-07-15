vector<int> rightSideView(TreeNode *root)
{
  vector<int> ans;
  if (root == NULL)
    return ans;
  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty())
  {
    int cnt = q.size();
    for (int i = 0; i < cnt; i++)
    {
      TreeNode *t = q.front();
      q.pop();

      if (i == cnt - 1)
        ans.push_back(t->val);
      if (t->left != NULL)
        q.push(t->left);
      if (t->right != NULL)
        q.push(t->right);
    }
  }
  return ans;
}