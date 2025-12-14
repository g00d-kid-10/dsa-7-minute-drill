int subarray_maximum(vector<int>& nums) {
    int ans = INT_MIN, sum = 0;
    for(int num : nums) {
        sum += num;
        if(num > sum) {
            sum = num;
        }

        ans = max(ans, sum);
    }

    return ans;
}