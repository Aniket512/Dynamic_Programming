vector<string> ans;
void solve(TreeNode *root, string temp)
{
  if (!root->left && !root->right)
  {
    ans.push_back(temp);
    return;
  }
  if (root->left)
    solve(root->left, temp + "->" + to_string(root->left->val));
  if (root->right)
    solve(root->right, temp + "->" + to_string(root->right->val));
}
vector<string> binaryTreePaths(TreeNode *root)
{
  string temp = to_string(root->val);
  solve(root, temp);
  return ans;
}