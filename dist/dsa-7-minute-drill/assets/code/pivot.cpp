int pivot(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1, ans = -1;
    while(l <= r) {
        if(nums[l] <= nums[r]) {
            ans = l;
            break;
        }
        
        int m = l + (r - l) / 2;
        if(nums[l] <= nums[m]) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return ans;
}