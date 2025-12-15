void move_zeros_to_end(vector<int>& nums) {
    int n = nums.size();
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) continue;
        swap(nums[i], nums[j]);
        j++;
    }
}