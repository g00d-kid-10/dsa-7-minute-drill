bool canPartition(vector<int>& input) {
    vector<int> nums = input;
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);

    vector<vector<int>> cache(n, vector<int>(total, -1));

    function<bool(int, int)> isPartible = [&](int i, int sum) -> bool {
        if (i >= n) return false;
        if (cache[i][sum] != -1) return cache[i][sum];
        if (sum == total - sum) return true;

        sum += nums[i];
        bool ans = isPartible(i + 1, sum);
        if (ans) {
            return cache[i][sum] = true;
        }

        sum -= nums[i];
        return cache[i][sum] = isPartible(i + 1, sum);
    };

    return isPartible(0, 0);
}