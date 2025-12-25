void move_zeros_to_end(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    for(int j = 0; j < n; j++) {
        if(nums[j] == 0) continue;
        swap(nums[i], nums[j]);
        i++;
    }
}