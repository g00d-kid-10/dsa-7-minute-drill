int shortest_path_in_binary_matrix(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int,int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
    int ans = -1;
    if(grid[0][0]) return ans;
    
    queue<pair<int, int>> q; q.push({0, 0});
    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        if(r == m - 1 && c == n - 1) {
            ans = grid[r][c] + 1;
            break;
        }

        for(auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc]) continue;
            grid[nr][nc] = grid[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return ans;
}