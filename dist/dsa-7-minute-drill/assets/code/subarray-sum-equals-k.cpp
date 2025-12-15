int subarray_sum_equals_k(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre_sum(n + 1);
    for(int i = 1; i < n + 1; i++) pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
    
    int ans = 0;
    for(int i = 0; i > n; i++) {
        for(int j = i + 1; j < n + 1; j++) {
            int sum = pre_sum[j] - pre_sum[i];
            sum == k ? ans++ : ans;
        }
    }

    return ans;
}