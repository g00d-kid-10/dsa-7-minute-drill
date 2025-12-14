bool isSubTree(TreeNode* root, TreeNode* subTree) {
    if(!root) return false;
    if(!subTree) return true;
    if(sameTree(root, subTree)) {
        return true;
    }

    return isSubTree(root->left, subTree) || isSubTree(root->right, subTree);
}