int minimum_path_sum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}};
    vector<vector<int>> cache(m, vector<int>(n, -1));
    
    function<int(int, int)> dfs = [&](int r, int c) -> int {
        if(r == m || c == n) return 1e9;
        if(r == m - 1 && c == n - 1) return grid[r][c];
        if(cache[r][c] != -1) return cache[r][c];

        int ans = 1e9;
        for(pair<int, int> dir : dirs) {
            int sub_ans = dfs(r + dir.first, c + dir.second);
            ans = min(ans, grid[r][c] + sub_ans);
        }

        return cache[r][c] = ans;
    };
    
    return dfs(0, 0);
}