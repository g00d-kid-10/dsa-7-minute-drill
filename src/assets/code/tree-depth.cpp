int depth(TreeNode* root) {
    if(!root) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return 1 + max(left, right);
}