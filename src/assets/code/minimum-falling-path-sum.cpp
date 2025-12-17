int minimum_falling_path_sum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<pair<int, int>> dirs = {{1, -1}, {1, 0}, {1, 1}};
    vector<vector<int>> cache(m, vector<int>(n, -1));

    function<int(int, int)> dfs = [&](int r, int c) -> int {
        if(r < 0 || c < 0 || r >= m || c >= n) return 1e9;
        if(r == m - 1) return matrix[r][c];
        if(cache[r][c] != -1) return cache[r][c];

        int ans = 1e9;
        for(pair<int, int> dir : dirs) {
            int next_step = dfs(r + dir.first, c + dir.second);
            ans = min(ans, matrix[r][c] + next_step);
        }

        return cache[r][c] = ans;
    };

    int ans = 1e9;
    for(int c = 0; c < n; c++) {
        ans = min(ans, dfs(0, c));
    }

    return ans;
}