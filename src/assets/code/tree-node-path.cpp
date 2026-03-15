bool path(TreeNode* root, TreeNode* target, vector<TreeNode*>& ans) {
    if(!root) return false;
    ans.push_back(root);
    if(root == target) {
        return true;
    }

    if(path(root->left, target, ans) || path(root->right, target, ans)) {
        return true;
    }
    
    ans.pop_back();

    return false;
}