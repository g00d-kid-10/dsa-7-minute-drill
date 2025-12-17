// DFS
vector<int> top_sort_dfs(int n, vector<vector<int>> edges) {
    vector<vector<int>> graph(n);
    for(vector<int> edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
    }

    vector<int> ans;
    vector<bool> visited(n);
    function<void(int)> dfs = [&](int node) -> void {
        if(visited[node]) return;
        visited[node] = 1;
        for(int nei : graph[node]) {
            dfs(nei);
        }
        ans.push_back(node);
    };

    for(int node = 0; node < n; node++) {
        if(!visited[node]) {
            dfs(node);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// BFS (aka Kahn's Algorithms)
vector<int> topo_sort_bfs(int n, vector<vector<int>> edges) {
    vector<vector<int>> graph(n);
    vector<int> indegrees(n);
    for(vector<int> edge : edges) {
        int u = edge[0], v = edge[1];
        graph[u].push_back(v);
        indegrees[v]++;
    }

    vector<int> ans;
    queue<int> q;
    for(int node = 0; node < n; node++) {
        if(indegrees[node] == 0) q.push(node);
    } 

    while(!q.empty()) {
        int node = q.front(); q.pop();
        ans.push_back(node);
        for(int nei : graph[node]) {
            indegrees[nei]--;
            if(indegrees[nei] == 0) {
                q.push(nei);
            }
        }
    }

    return ans.size() != n ? vector<int>() : ans;
}