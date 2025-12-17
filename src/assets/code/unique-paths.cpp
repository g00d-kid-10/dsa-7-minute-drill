int unique_paths(int m, int n) {
    vector<vector<int>> cache(m, vector<int>(n, -1));
    function<int(int, int)> dfs = [&](int r, int c) -> int {
        if(r < 0 || c < 0 || r >= m || c >= n) return 0;
        if(r == m - 1 && c == n -1) return 1;
        if(cache[r][c] != -1) return cache[r][c];

        int ans = 0;
        ans += dfs(r + 1, c);
        ans += dfs(r, c + 1);
        return cache[r][c] = ans;
    };

    return dfs(0, 0);
}