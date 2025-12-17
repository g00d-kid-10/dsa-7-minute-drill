vector<int> eventual_safe_nodes_topo_sort(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> indegrees(n);
    vector<vector<int>> rev(n);
    for(int u = 0; u < n; u++) {
        for(int v : graph[u]) {
            rev[v].push_back(u);
            indegrees[u]++;
        }
    }

    queue<int> q;
    for(int node = 0; node < indegrees.size(); node++) {
        if(indegrees[node] == 0) {
            q.push(node);
        }
    }

    vector<int> ans;
    while(!q.empty()) {
        int node = q.front(); q.pop();
        ans.push_back(node);
        for(int nei : rev[node]) {
            if(--indegrees[nei] == 0) {
                q.push(nei);
            }
        }
    }

    sort(ans.begin(), ans.end());
    return ans;
}
