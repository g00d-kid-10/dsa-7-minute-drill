int number_of_connected_component(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> vis(n, false);
    int components = 0;

    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (int v : graph[u])
            if (!vis[v]) dfs(v);
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            components++;
            dfs(i);
        }
    }

    return components;
}