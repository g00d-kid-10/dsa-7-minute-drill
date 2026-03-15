// Input: nums = [1,1,2,3,3,4,4,8,8]
// [1,1,2,3,3,4,4,8,8]
// [0,1,2,3,4,5,6,7,8]
// Output: 2

// Single element causes disturbance in indexing order of dual element [Ideally=> first:even second:odd]
// Binary search towards the disturbed part
// Based on mid[Even/Odd]

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while(l < r) {
        int m = l + (r - l) / 2;
        if(m & 1) m--; // make it even if it's odd
        if(nums[m] == nums[m + 1]) {
            l = m + 2;
        } else {
            r = m;
        }
    }
    return nums[l];
}