bool is_valid_bst(TreeNode* root) {
    function<bool(TreeNode*, long long, long long)> dfs = [&](TreeNode* root, long long left, long long right) -> bool {
        if(!root) return true;
        if(!(root->val > left && root->val < right)) return false;
        return dfs(root->left, left, root->val) && dfs(root->right, root->val, right);
    };

    return dfs(root, LLONG_MIN, LLONG_MAX);
}