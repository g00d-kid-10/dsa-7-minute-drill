// Cooldown is one day
// Input: prices = [1,2,3,0,2]
// Output: 3
// Explanation: transactions = [buy, sell, cooldown, buy, sell]

int max_profit_with_cooldown(vector<int>& prices) {
    int n = prices.size();

    function<int(int,bool)> dfs = [&](int i, bool hold) -> int {
        if (i >= n) return 0;

        if (!hold) {
            int buy = -prices[i] + dfs(i + 1, true);
            int skip = dfs(i + 1, false);
            return max(buy, skip);
        } else {
            int sell = prices[i] + dfs(i + 2, false); // cooldown
            int skip = dfs(i + 1, true);
            return max(sell, skip);
        }
    };

    return dfs(0, false);
}