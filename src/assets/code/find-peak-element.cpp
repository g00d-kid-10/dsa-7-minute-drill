/**
 * https://leetcode.com/problems/find-peak-element/description/
 * A peak element is an element that is strictly greater than its neighbors.
 * Find a peak element index.
 * May contains multiple peaks
 * You may imagine that nums[-1] = nums[n] = -∞.
 * nums[i] != nums[i + 1] for all valid i.
 */

int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while(l < r) {
        int m = l + (r - l) / 2;
        if(nums[m] < nums[m + 1]) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}