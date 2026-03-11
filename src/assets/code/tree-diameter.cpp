int tree_diameter(TreeNode* root) {
    int ans = 0;
    function<int(TreeNode*)> depth = [&](TreeNode* root) -> int {
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right);
        return 1 + max(left, right);
    };

    depth(root);
    
    return ans;
}