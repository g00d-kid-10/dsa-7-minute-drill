// RECURSIVE
void rotate_array(vector<int>& nums, int k) {
    int n = nums.size();
    reverse(nums.begin(), nums.begin() + k % n);
    reverse(nums.begin() + k % n, nums.end());
    reverse(nums.begin(), nums.end());
    // for right rotation reverse the 3 process
}

// ITERATIVE
void rotate_array(vector<int>& nums, int k) {
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