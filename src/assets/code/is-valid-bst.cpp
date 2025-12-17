bool is_valid_bst(TreeNode* root) {
    function<bool(TreeNode*, long long, long long)> dfs = [&](TreeNode* root, long long l, long long r) -> bool {
        if (!root) return true;
        if (root->val <= l || root->val >= r) return false;
        return dfs(root->left, l, root->val) && dfs(root->right, root->val, r);
    };

    return dfs(root, LLONG_MIN, LLONG_MAX);
}