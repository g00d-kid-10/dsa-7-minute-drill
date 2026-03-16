int minimum_path_sum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
    vector<vector<int>> cache(m, vector<int>(n, -1));
    
    function<int(int, int)> dfs = [&](int r, int c) -> int {
        if(r == m || c == n) return 1e9;
        if(r == m - 1 && c == n - 1) return grid[r][c];
        if(cache[r][c] != -1) return cache[r][c];
    
        int minimum = 1e9;
        for(auto& [dr, dc] : dirs) {
            minimum = min(minimum, dfs(r + dr, c + dc));
        }

        return cache[r][c] = grid[r][c] + minimum;
    };
    
    return dfs(0, 0);
}