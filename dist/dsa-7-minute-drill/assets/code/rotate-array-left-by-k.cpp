void rotate_array_left_by_k(vector<int>& nums, int k) {
    int n = nums.size();
    reverse(nums.begin(), nums.begin() + k % n);
    reverse(nums.begin() + k % n, nums.end());
    reverse(nums.begin(), nums.end());
}