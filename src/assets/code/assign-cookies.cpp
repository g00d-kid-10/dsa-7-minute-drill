int assign_cookies(vector<int>& g, vector<int>& s) {
    int ans = 0, n = g.size(), m = s.size();
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    for(int i = n - 1, j = m - 1; (i > -1 && j > -1); i--) {
        if(s[j] >= g[i]) {
            ans++;
            j--;
        }
    }
    return ans;
}