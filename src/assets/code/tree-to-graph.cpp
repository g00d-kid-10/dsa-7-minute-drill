unordered_map<int, vector<int>> tree_to_graph(TreeNode* root) {
    unordered_map<int, vector<int>> graph;
    
    function<void(TreeNode*, TreeNode*)> tree_to_graph = [&](TreeNode* r, TreeNode* p) -> void {
        if(r && p) {
            graph[p->val].push_back(r->val);
            graph[r->val].push_back(p->val);
        }
    
        if(r->left) tree_to_graph(r->left, r);
        if(r->right) tree_to_graph(r->right, r);
    };

    tree_to_graph(root, nullptr);
    
    return graph;
}
