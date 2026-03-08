int shortest_path_unweighted_graph(vector<vector<int>>& graph, int src, int dest) {
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> q;
    
    dist[src] = 0;
    q.push(src); 
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(u == dest) return dist[dest];
        for(int v : graph[u]) {
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    return -1;
}