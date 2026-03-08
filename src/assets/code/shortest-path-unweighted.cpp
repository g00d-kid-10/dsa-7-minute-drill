int shortest_path_unweighted_graph(vector<vector<int>>& graph, int src, int dest) {
    int n = graph.size();
    vector<int> ans(n, INT_MAX);
    queue<int> q;
    
    ans[src] = 0;
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

    return ans[dest];
}