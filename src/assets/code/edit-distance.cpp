int edit_distance(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> cache;
    cache.resize(m + 1, vector<int>(n + 1, -1));

    function<int(int,int)> dfs = [&](int i, int j) -> int {
        if (i >= m) return n - j;
        if (j >= n) return m - i;
        if (cache[i][j] != -1) return cache[i][j];

        int ans = 0;
        if (s1[i] == s2[j]) {
            ans = dfs(i + 1, j + 1);
        } else {
            int ins = 1 + dfs(i, j + 1);
            int del = 1 + dfs(i + 1, j);
            int rep = 1 + dfs(i + 1, j + 1);
            ans = min({ins, del, rep});
        }

        return cache[i][j] = ans;
    };

    return dfs(0, 0);
}
