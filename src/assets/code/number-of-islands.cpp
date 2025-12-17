int number_of_islands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    const vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    function<int(int, int)> dfs = [&](int r, int c) -> int {
        if(r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') return 0;

        grid[r][c] = '0';
        for(pair<int, int> dir : dirs) {
            int nr = r + dir.first;
            int nc = c + dir.second;
            dfs(nr, nc);
        }

        return 1;
    };

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            ans += dfs(i, j);
        }
    }

    return ans;
}