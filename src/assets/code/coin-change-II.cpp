// Return the number of combinations that make up that amount. If combination not possible return 0.
// Infinite coins available.
// Input: amount = 5, coins = [1,2,5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1
int change(int amount, vector<int>& coins) {
    vector<int> nums;
    int n, target;
    vector<vector<int>> cache;

    nums = coins;
    n = coins.size();
    target = amount;
    cache.resize(n + 1, vector<int>(amount + 1, -1));

    function<int(int,int)> dfs = [&](int i, int target) -> int {
        if (i >= n || target < 0) return 0;
        if (target == 0) return 1;
        if (cache[i][target] != -1) return cache[i][target];

        int pick = dfs(i, target - nums[i]);
        int dont_pick = dfs(i + 1, target);
        return cache[i][target] = pick + dont_pick;
    };

    return dfs(0, amount);
}