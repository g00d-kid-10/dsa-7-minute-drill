vector<int> shrotest_path_undireted_weighted_graph(vector<vector<pair<int, int>>> graph, int src) {
    // dijkstra's algo
    int n = graph.size();
    vector<int> dis(n, INT_MAX), parent(n, -1);
    dis[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [_, node] = pq.top(); pq.pop();
        for(auto [weight, nei] : graph[node]) {
            if(dis[node] + weight < dis[nei]) {
                dis[nei] = dis[node] + weight;
                pq.push({dis[nei], nei});
                // parent[nei] = node;
            }
        }
    }
    /*
    // To PRINT THE PATH
        int dest = m;
        if(dist[dest]) reutrn path; // no path
        vector<int> path;
        for(int v = dest; v != -1; v = parent[node]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
    */
    return dis;
}
