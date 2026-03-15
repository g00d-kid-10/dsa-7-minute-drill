// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

int tree_diameter(TreeNode* root) {
    int ans = 0;
    function<int(TreeNode*)> depth = [&](TreeNode* root) -> int {
        if(!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ans = max(ans, left + right); // left + right => number of edges; left + right + 1 => number of nodes
        return 1 + max(left, right);
    };

    depth(root);
    
    return ans;
}