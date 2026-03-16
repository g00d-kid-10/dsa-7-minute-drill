// Input: text1 = "abcde", text2 = "ace" 
// Output: 3  
// Explanation: The longest common subsequence is "ace" and its length is 3.
int longest_common_subsequence(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> cache(m, vector<int>(n, -1));
    
    function<int(int,int)> dfs = [&](int i, int j) -> int {
        if (i >= m || j >= n) return 0;
        if (cache[i][j] != -1) return cache[i][j];

        int ans = 0;
        if (s1[i] == s2[j]) {
            ans = 1 + dfs(i + 1, j + 1);
        } else {
            ans = max(dfs(i + 1, j), dfs(i, j + 1));
        }

        return cache[i][j] = ans;
    };

    return dfs(0, 0);
}
