unordered_map<int, int> m;
TreeNode *solve(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie)
{
  if (ps > pe || is > ie)
    return NULL;
  TreeNode *root = new TreeNode(preorder[ps]);

  int inRoot = m[preorder[ps]];
  int numsLeft = inRoot - is;
  root->left = solve(preorder, ps + 1, ps + numsLeft, inorder, is, inRoot - 1);
  root->right = solve(preorder, ps + numsLeft + 1, pe, inorder, inRoot + 1, ie);
  return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
  int n = preorder.size();
  for (int i = 0; i < preorder.size(); i++)
  {
    m[inorder[i]] = i;
  }
  TreeNode *root = solve(preorder, 0, n - 1, inorder, 0, n - 1);
  return root;
}
