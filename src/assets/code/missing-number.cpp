int missing_number(vector<int>& nums) {
    int n = nums.size();
    int t_sum = n * (n + 1) / 2;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    return t_sum - sum;

}