int remove_duplicate_from_sorted(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    for(int i = 0, int j = 0; j < n; j++) {
        if(nums[i] == nums[j]) continue;
        i++;
        nums[i] = nums[j];
    }

    return i + 1;
}