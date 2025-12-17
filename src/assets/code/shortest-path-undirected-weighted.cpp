vector<int> shrotest_path_udwg(vector<vector<pair<int, int>>> graph, int src) {
    // dijkstra's algo
    int n = graph.size();
    vector<int> dis(n, INT_MAX);
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
        vector<int> path;
        int dest = m;
        while(parent[dest] != dest) {
            path.push_back(dest);
            dest = parent[dest];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
    */
    return dis;
}
