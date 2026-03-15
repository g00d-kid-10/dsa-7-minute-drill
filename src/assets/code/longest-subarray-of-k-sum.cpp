int longest_subarray_of_k_sum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0, ans = 0;
    for(int i = 0, j = 0; j < n; j++) {
        sum += nums[j];
        while(i <= j && sum > k) {
            sum -= nums[i++];
        }
        
        if(sum == k) { // Remove this condition for at least k sum
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
}

// Applications:
// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/