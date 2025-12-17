int house_robber(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        function<int(int, int)> solve = [&](int l, int r) -> int {
            vector<int> cache(n, -1);
            function<int(int)> dfs = [&](int i) -> int {
                if(i > r) return 0;
                if(cache[i] != -1) return cache[i];
        
                int take = nums[i] + dfs(i + 2);
                int dont_take = dfs(i + 1);
                return cache[i] = max(take, dont_take);
            };
            return dfs(l);
        };
        
        return max(solve(0, n - 2), solve(1, n - 1));
}