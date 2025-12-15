void next_permutation(vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;
    while(i > -1 && nums[i] > nums[i + 1]) i--;
    if(i == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    int idx = upper_bound_dec_order(nums, i + 1, n - 1, nums[i]);
    swap(nums[i], nums[idx]);
    reverse(nums.begin() + i + 1, nums.end());
}