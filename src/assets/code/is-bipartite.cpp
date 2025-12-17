bool is_bipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> colors(n, -1);
    
    function<bool(int, int)> dfs = [&](int i, int color) {
        colors[i] = color;
        for(int nei : graph[i]) {
            if(colors[nei] == -1) {
                if(!dfs(nei, !color)) {
                    return false;
                }
            } else if(colors[nei] == color) {
                return false;
            }
        }

        return true;
    };

    for (int i = 0; i < n; i++) {
        if(colors[i] == -1) {
            if (!dfs(i, 0))
                return false;
        }
    }
    return true;
}