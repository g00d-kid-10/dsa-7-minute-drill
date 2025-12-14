bool dfs(TreeNode* root, int l, int r) {
    if(!root) return true;
    if(root->val <= l || root->val >= r) return false;
    return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
}
bool is_valid_bst(TreeNode* root) {
    return dfs(root, INT_MIN, INT_MAX);
}