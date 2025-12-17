int house_robber(vector<int>& nums) {
    int n = nums.size();
    vector<int> cache(n, -1);

    function<int(int)> dfs = [&](int i) {
        if(i >= n) return 0;
        if(cache[i] != -1) return cache[i];

        int take = nums[i] + dfs(i + 2);
        int dont_take = dfs(i + 1);
        return cache[i] = max(take, dont_take);
    }
    
    return dfs(0);    
}