bool isSymmetric(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty())
    {
        TreeNode *s = q.front();
        q.pop();
        TreeNode *t = q.front();
        q.pop();
        if (!s && !t)
            continue;
        if (!s || !t)
            return false;
        if (s->val != t->val)
            return false;

        q.push(s->left);
        q.push(t->right);
        q.push(s->right);
        q.push(t->left);
    }
    return true;
}