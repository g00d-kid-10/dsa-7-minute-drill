int max_profit_buy_sell_stock_multiple_transaction(vector<int>& prices) {
    int ans = 0;
    for(int i = 1; i < prices.size(); i++) {
        int profit = prices[i] - prices[i - 1];
        if(profit >= 0) {
            ans += profit;
        }
    }

    return ans;
}