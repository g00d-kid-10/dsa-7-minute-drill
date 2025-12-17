vector<int> shortest_path_dawg(vector<vector<pair<int, int>>> graph, int src) {
    int n = graph.size();
    
    vector<int> visited(n);
    // toposort dfs
    stack<int> s;
    function<void(int)> dfs = [&](int node) -> void {
        if(visited[node]) return;
        visited[node] = 1;
        for(auto [nei, _] : graph[node]) {
            dfs(nei);
        }
        s.push(node);
    };

    // toposort
    for(int node = 0; node < n; node++) {
        if(!visited[node]) {
            dfs(node);
        }
    }
    
    vector<int> ans(n, INT_MAX);
    ans[src] = 0;
    while(!s.empty()) {
        int node = s.top(); s.pop();
        if(ans[node] != INT_MAX) { // Nodes that come before the source in topological order are effectively ignored because they are not reachable from the source.
            for(auto [nei, weight] : graph[node]) {
                ans[nei] = min(ans[nei], ans[node] + weight);
            }
        }
    }

    return ans;
}
