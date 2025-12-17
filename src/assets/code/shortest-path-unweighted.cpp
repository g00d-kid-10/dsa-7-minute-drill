vector<int> shortest_path_unweighted_graph(vector<vector<int>>& graph, int src) {
    int n = graph.size();
    
    vector<int> ans(n, INT_MAX);
    ans[src] = 0;

    queue<int> q;
    q.push(src);
    while(!q.empty()) {
        int node = q.front(); q.pop();
        for(int nei : graph[node]) {
            if(ans[nei] == INT_MAX) {
                ans[nei] = ans[node] + 1;
                q.push(nei);
            }
        }
    }

    return ans;
}