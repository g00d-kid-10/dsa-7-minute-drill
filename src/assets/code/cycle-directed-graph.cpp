// DFS
bool is_cyclic_directed_graph_dfs(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n, false), branch(n, false);

    function<bool(int)> dfs = [&](int node) -> bool {
        visited[node] = true;
        branch[node] = true;

        for (int nei : graph[node]) {
            if (!visited[nei] && dfs(nei)) return true;
            if (branch[nei]) return true;
        }

        branch[node] = false;
        return false;
    };

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if(dfs(i)) return true;
        }
    }

    return false;
}

// BFS
bool is_cyclic_directed_graph_bfs(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indegrees(n, 0);

    for (int node = 0; node < n; node++)
        for (int nei : graph[node])
            indegrees[nei]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegrees[i] == 0) q.push(i);

    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        count++;
        for (int nei : graph[node]) {
            if (--indegrees[nei] == 0) {
                q.push(nei);
            }
        }
    }

    return count != n;  // cycle exists if not all nodes processed
}

