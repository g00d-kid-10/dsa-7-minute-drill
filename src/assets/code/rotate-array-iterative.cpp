void rotate_array_iterative(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n;
    vector<int> ans(n);
    for(int i = 0; i < n; i++) {
        // i -> reps left
        // (i + K) % n -> reps right
        ans[(i + k) % n] = nums[i]; // right -> pushing from left(i) to right((i + k) % n).
        nums[i] = ans[(i + k) % n]; // left -> pulling from right to left.
    }
    nums = ans;
}