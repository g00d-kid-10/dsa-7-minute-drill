vector<int> tree_traversal(TreeNode* root) {
    vector<int> ans;
    function<void(TreeNode*)> dfs = [&](TreeNode* root) -> void {
        if(!root) return;
        // pre_order ans.push_back(root->val);
        if(root->left) dfs(root->left);
        // in_order
        if(root->right) dfs(root->right);
        // post_order
    };

    dfs(root);
    
    return ans;
}