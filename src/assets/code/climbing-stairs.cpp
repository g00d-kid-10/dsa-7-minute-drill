int climb_stairs(int n) {
    vector<int> cache(n, -1);
    function<int(int)> dfs = [&](int i) {
        if(i >= n) {
            if(i == n) return 1;
            return 0;
        }

        if(cache[i] != -1) return cache[i];

        int ans = 0;
        ans += dfs(i + 1);
        ans += dfs(i + 2);
    
        return cache[i] = ans;
    };
    
    return dfs(0);
}