int minimum_effort_path(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
    ans[0][0] = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, 0}});
    while(!pq.empty()) {
        auto [d, cell] = pq.top(); pq.pop();
        auto [r, c] = cell;
        if(r == m - 1  && c == n - 1) {
            return d;
        }
        
        for(auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
            
            int diff = max(ans[r][c], abs(heights[nr][nc] - heights[r][c]));
            if(diff < ans[nr][nc]) {
                ans[nr][nc] = diff;
                pq.push({diff, {nr, nc}});
            }
        }        
    }

    return -1;
}
