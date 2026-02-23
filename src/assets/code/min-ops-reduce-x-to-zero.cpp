// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/

// k = total_sum - x
// n - length of largest subbarray with k sum

int min_ops_to_reduce_x_to_zero(vector<int>& nums, int x) {
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    int X = total - x;
    
    int sum = 0, size = -1;
    for(int i = 0, j = 0; j < n; j++) {
        sum += nums[j];
        while(i <= j && sum > X) {
            sum -= nums[i++];
        }
        
        if(sum == X) {
            size = max(size, j - i + 1);
        }
    }

    return size == -1 ? -1 : n - size;
}