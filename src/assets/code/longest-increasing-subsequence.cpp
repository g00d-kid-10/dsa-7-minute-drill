// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
int longest_increasing_subsequence(vector<int>& nums) {
    int n;
    unordered_map<long long, int> cache;
    n = nums.size();

    function<int(int,int)> dfs = [&](int i, int j) -> int {
        if (j == n) return 0;
        long long key = ((long long)i << 32) | (unsigned long long)j;
        if (cache.count(key)) return cache[key];

        int ans = dfs(i, j + 1);
        if (i == -1 || nums[i] < nums[j]) {
            ans = max(ans, 1 + dfs(j, j + 1));
        }

        return cache[key] = ans;
    };

    return dfs(-1, 0);
}

// Iterative Version - Most Fast
int longest_increasing_subsequence(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for(int i = n - 2; i >= 0; i--) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] < nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
    }

    int ans = 0;
    for(int num : dp) ans = max(ans, num);
    return ans; 
}