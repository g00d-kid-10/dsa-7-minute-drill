int find_cheapest_flight_with_k_stops(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> graph(n);
    for(vector<int> flight : flights) {
        int u = flight[0], v = flight[1], w = flight[2];
        graph[u].push_back({v, w});
    }

    vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
    dist[src][0] = 0;
    
    int ans = -1;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, src, 0});
    while(!pq.empty()) {
        auto [d, node, steps] = pq.top(); pq.pop();
        if(node == dst) {
            ans = d;
            break;
        }

        if(steps > k) {
            continue;
        }
        
        for(auto [nei, w] : graph[node]) {
            if(d + w < dist[nei][steps + 1]) {
                dist[nei][steps + 1] = d + w;
                pq.push({d + w, nei, steps + 1});
            }
        }
    }

    return ans;
}
