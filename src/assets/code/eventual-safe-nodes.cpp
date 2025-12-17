
// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

// DFS
vector<int> eventual_safe_nodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<bool> visited(n), branch(n);
    vector<int> ans;

    function<bool(int)> dfs = [&](int node) -> bool {
        if(branch[node]) return true;
        if(visited[node]) return false;
        
        visited[node] = 1, branch[node] = 1;
        for(int nei : graph[node]) {
            if(dfs(nei)) {
                return true;
            }
        }
        branch[node] = 0;
        ans.push_back(node);
        return false;
    };

    for(int node = 0; node < n; node++) {
        if(!visited[node]) {
            dfs(node);
        }
    }

    return ans;
}

// BFS
vector<int> eventual_safe_nodes(vector<vector<int>>& graph) {
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