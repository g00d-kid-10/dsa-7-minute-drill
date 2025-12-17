// Input: prices = [1,3,2,8,4,9], fee = 2
// Output: 8
// Explanation: The maximum profit can be achieved by:
// - Buying at prices[0] = 1
// - Selling at prices[3] = 8
// - Buying at prices[4] = 4
// - Selling at prices[5] = 9
// The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

// CACHING IS IGNORED
int max_profit_transaction_fee(vector<int>& prices, int fee) {
    int n = prices.size();

    function<int(int, int)> dfs = [&](int i, int hold) -> int {
        if(i >= n) return 0;

        if(!hold) {
            int buy = -prices[i] + dfs(i + 1, true);
            int skip = dfs(i + 1, false);
            return max(buy, skip);
        } else {
            int sell = prices[i] - fee + dfs(i + 1, false);
            int skip = dfs(i + 1, true);
            return max(sell, skip);
        }
    };

    return dfs(0, false);
}