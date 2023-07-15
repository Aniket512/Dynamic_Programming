int findLeft(TreeNode *root)
{
  int ans = 0;
  while (root)
  {
    ans++;
    root = root->left;
  }
  return ans;
}
int findRight(TreeNode *root)
{
  int ans = 0;
  while (root)
  {
    ans++;
    root = root->right;
  }
  return ans;
}
int countNodes(TreeNode *root)
{
  if (!root)
    return 0;

  int lh = findLeft(root);
  int lr = findRight(root);

  if (lh == lr)
    return pow(2, lh) - 1;

  return 1 + countNodes(root->left) + countNodes(root->right);
}
