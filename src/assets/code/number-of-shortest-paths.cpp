int number_of_shortest_path_to_dest(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph(n);
    for(auto& road : roads) {
        int u = road[0], v = road[1], w = road[2];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> dist(n, INT_MAX), ways(n);
    dist[0] = 0; ways[0] = 1;

    using T = pair<int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        for(auto& [v, w] : graph[u]) {
            int nd = d + w;
            if(nd < dist[v]) {
                dist[v] = d + w;
                ways[v] = ways[u];
                pq.push({d + w, v});
            } else if(nd == dist[v]) {
                ways[v] += ways[u];
            }
        }
    }

    return ways[n - 1];
}
