// Input: s = "bbbab"
// Output: 4
// Explanation: One possible longest palindromic subsequence is "bbbb".
int longestPalindromeSubseq(string s) {
    vector<vector<int>> cache;

    int n = s.size();
    cache.resize(n + 1, vector<int>(n + 1, -1));
    function<int(int,int)> dfs = [&](int i, int j) -> int {
        if (j < i) return 0;
        if (j == i) return 1;
        if (cache[i][j] != -1) return cache[i][j];

        int ans = 0;
        if (s[i] == s[j]) {
            ans = 2 + dfs(i + 1, j - 1);
        } else {
            ans = max(dfs(i + 1, j), dfs(i, j - 1));
        }

        return cache[i][j] = ans;
    };

    return dfs(0, n - 1);
}
