// DIJKESTRA'S ALGO
int shrotest_path_weighted_graph(vector<vector<pair<int,int>>>& graph, int src, int dest) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // vector<int> parent(n, -1);
    
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(d > dist[u]) continue;
        if(u == dest) return d;
        for(auto& [v, w] : graph[u]) {
            int nd = d + w;
            if(nd < dist[v]) {
                dist[v] = nd;
                pq.push({nd, v});
                // parent[v] = u;
            }
        }
    }
    return -1;
}

/*
// To PRINT THE PATH
    vector<int> path;
    if(dist[dest] == INT_MAX) reutrn path;
    for(int u = dest; u != -1; u = parent[u]) {
        path.push_back(u);
    }
    reverse(path.begin(), path.end());

// WHY PRIORITY QUEUE?
//  If we explore the path with shorter distance in priority,
//  The different paths leading to the same node, shorter path's are explored first,
//  Hence the longer path nodes never get pushed into the queue begin shorter path which was already explored,
//  Hence saves the cost of explorations along longer path.
//  PS: It results in elimination of the cost of exploration of the longer paths leading to the same node.
*/
