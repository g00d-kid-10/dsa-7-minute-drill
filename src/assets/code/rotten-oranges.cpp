int rotten_oranges(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    
    queue<pair<int, int>> q;
    int fresh = 0;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(grid[i][j] == 2)
                q.push({i, j});
            else if(grid[i][j] == 1)
                fresh++;

    int ans = 0;
    while(!q.empty()) {
        if(!fresh) break;
        int size = q.size();
        while(size--) {
            auto [r, c] = q.front(); q.pop();
            for(auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < 0 || nc < 0 || nr >= m || nc >= n || grid[nr][nc] == 2 || grid[nr][nc] == 0) {
                    continue;
                }
                grid[nr][nc] = 2; fresh--;
                q.push({nr, nc});
            }
        }
        ans++;
    }

    return fresh == 0 ? ans : -1;
}