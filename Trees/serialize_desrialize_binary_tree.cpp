// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
  if (!root)
    return "";
  queue<TreeNode *> q;
  q.push(root);
  string ans = "";
  while (!q.empty())
  {
    TreeNode *t = q.front();
    q.pop();
    if (t == NULL)
    {
      ans += "#,";
      continue;
    }
    ans += (to_string(t->val) + ',');
    q.push(t->left);
    q.push(t->right);
  }
  return ans;
}

// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
  if (data.size() == 0)
    return NULL;
  stringstream s(data);
  string str;
  getline(s, str, ',');
  TreeNode *root = new TreeNode(stoi(str));
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty())
  {
    TreeNode *t = q.front();
    q.pop();
    getline(s, str, ',');

    if (str == "#")
    {
      t->left = NULL;
    }
    else
    {
      t->left = new TreeNode(stoi(str));
      q.push(t->left);
    }

    getline(s, str, ',');

    if (str == "#")
    {
      t->right = NULL;
    }
    else
    {
      t->right = new TreeNode(stoi(str));
      q.push(t->right);
    }
  }
  return root;
}
