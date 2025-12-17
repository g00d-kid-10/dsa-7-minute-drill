int no_of_land_cells_not_leading_to_border(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    function<void(int, int)> dfs = [&](int r, int c) {
        if(r < 0 || c < 0 || r >= m || c >= n || !grid[r][c]) return;
        grid[r][c] = 0;
        for(auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            dfs(nr, nc);
        }
    };

    for (int i = 0; i < m; i++) {
        if (grid[i][0] == 1) dfs(i, 0);
        if (grid[i][n-1] == 1) dfs(i, n-1);
    }
    for (int j = 0; j < n; j++) {
        if (grid[0][j] == 1) dfs(0, j);
        if (grid[m-1][j] == 1) dfs(m-1, j);
    }

    int ans = 0;
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            if(grid[r][c]) ans++;
        }
    }

    return ans;
}