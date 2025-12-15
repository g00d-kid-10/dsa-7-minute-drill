int search(vector<int>& nums, int val) {
    int n = nums.size();
    int l = 0, r = n - 1, ans = -1;
    while(l <= r) {
        int m = l + (r - l) / 2;
        if(nums[m] > val) {
            r = m - 1;
        } else if(nums[m] < val) {
            l = m + 1;
        } else {
            ans = m;
            break;
        }
    }
    return ans;
}