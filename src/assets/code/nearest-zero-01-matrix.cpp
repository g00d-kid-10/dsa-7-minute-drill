vector<vector<int>> nearest_zero_wrt_cells_in_01_grid(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<pair<int, int>> q;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(!mat[i][j]) q.push({i, j}); else mat[i][j] = -1;

    while(!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for(auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if(nr < 0 || nc < 0 || nr >= m || nc >= n || mat[nr][nc] != -1) continue;
            mat[nr][nc] = mat[r][c] + 1;
            q.push({nr, nc});
        }
    }

    return mat;
}