// Return the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
int coin_change(vector<int>& coins, int amount) {
    vector<int> nums = coins;
    int n = nums.size(), target = amount;
    vector<vector<int>> cache(n + 1, vector<int>(amount + 1, -1));

    function<int(int,int)> dfs = [&](int i, int target) -> int {
        if (i >= n || target < 0) return 1e9;
        if (target == 0) return 0;
        if (cache[i][target] != -1) return cache[i][target];

        int pick = 1 + dfs(i, target - nums[i]);
        int dont_pick = dfs(i + 1, target);
        return cache[i][target] = min(pick, dont_pick);
    };

    int ans = dfs(0, amount);
    return ans == 1e9 ? -1 : ans;
}