// Single element causes disturbance in indexing order of dual element [Ideally=> first:even second:odd]
// Binary search towards the disturbed part
// Based on mid[Even/Odd]

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while(l < r) {
        int m = l + (r - l) / 2;
        if(m & 1) {
            if(nums[m - 1] == nums[m]) {
                l = m + 1;
            } else {
                r = m;
            }
        } else {
            if(nums[m] == nums[m + 1]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
    }

    return nums[l];
}