// DFS
bool is_cyclic_undirected_graph_dfs(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);

    function<bool(int,int)> dfs = [&](int node, int parent) -> bool {
        visited[node] = true;
        for (int nei : graph[node]) {
            if (!visited[nei]) {
                if (dfs(nei, node)) return true;
            } else if (nei != parent) {
                return true;
            }
        }
        return false;
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if(dfs(i, -1)) return true;
        }
    }
        
    return false;
}

// BFS
bool is_cyclic_undirected_graph_bfs(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;

        queue<pair<int,int>> q;
        q.push({i, -1});
        visited[i] = true;

        while (!q.empty()) {
            auto [node, parent] = q.front(); q.pop();
            for (int nei : graph[node]) {
                if (!visited[nei]) {
                    visited[nei] = true;
                    q.push({nei, node});
                } else if (nei != parent) {
                    return true;
                }
            }
        }
    }
    return false;
}
