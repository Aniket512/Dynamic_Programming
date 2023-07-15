int widthOfBinaryTree(TreeNode *root)
{
  queue<pair<TreeNode *, long long>> q;
  q.push({root, 0});

  int ans = 1;
  while (!q.empty())
  {
    int num1, num2;
    int c = q.size();
    int mn = q.front().second;
    for (int i = 0; i < c; i++)
    {

      TreeNode *t = q.front().first;
      long long cnt = q.front().second - mn;
      q.pop();

      if (i == 0)
        num1 = cnt;
      if (i == c - 1)
        num2 = cnt;

      ans = max(ans, num2 - num1 + 1);
      if (t->left)
        q.push({t->left, 2 * (cnt)});
      if (t->right)
        q.push({t->right, 2 * (cnt) + 1});
    }
  }

  return ans;
}
