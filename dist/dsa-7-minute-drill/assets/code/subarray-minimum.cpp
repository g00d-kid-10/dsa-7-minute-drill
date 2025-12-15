int subarray_minimum(vector<int>& nums) {
    int ans = INT_MAX, sum = 0;
    for(int num : nums) {
        sum += num;
        if(num < sum) {
            sum = num;
        }
        
        ans = min(ans, sum);
    }

    return ans;
}