int upper_bound_dec_order(vector<int>& nums, int l, int r, int val) {
    int n = nums.size();
    int l = 0, r = n - 1, ans = n;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] > val) {
            ans = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return ans;
}