int max_profit_buy_sell_stock(vector<int>& prices) {
    int n = prices.size();
    int profit = 0, ans = 0;
    for(int i = 1; i < n; i++) {
        profit += prices[i] - prices[i - 1];
        if(profit < 0) {
            profit = 0;
        }
        ans = max(ans, profit);
    }
    return ans;
}