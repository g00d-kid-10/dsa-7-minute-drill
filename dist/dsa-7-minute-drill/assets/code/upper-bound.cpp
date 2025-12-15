int upper_bound(vector<int>& nums, int val) {
    int n = nums.size();
    int l = 0, r = n - 1, ans = n;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] > val) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return ans;
}