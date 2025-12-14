int remove_duplicate_from_sorted(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(nums[j] == nums[i]) continue;
        j++;
        nums[j] = nums[i];
    }

    return j + 1;
}