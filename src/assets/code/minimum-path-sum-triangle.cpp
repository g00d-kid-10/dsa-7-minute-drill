int minimum_path_sum_triangle(vector<vector<int>>& triangle) {
    int m = triangle.size();
    vector<vector<int>> cache(m, vector<int>(m, -1));

    function<int(int, int)> dfs = [&](int r, int c) {
        if(r >= m) INT_MAX;
        if(r == m - 1) return triangle[r][c];
        if(cache[r][c] != -1) return cache[r][c];
        return cache[r][c] = triangle[r][c] + min(dfs(r + 1, c), dfs(r + 1, c + 1));
    };

    return dfs(0, 0);
}