vector<int> eventual_safe_nodes_dfs_cycle(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n), branch(n);
    vector<int> ans;

    function<bool(int)> dfs = [&](int node) -> bool {
        if(branch[node]) return true;
        if(visited[node]) return false;
        
        visited[node] = 1, branch[node] = 1;
        for(int nei : graph[node]) {
            if(dfs(nei)) {
                return true;
            }
        }
        branch[node] = 0;
        ans.push_back(node);
        return false;
    };

    for(int node = 0; node < n; node++) {
        if(!visited[node]) {
            dfs(node);
        }
    }

    return ans;
}
