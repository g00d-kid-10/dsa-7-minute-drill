// HASMAP => For integers
int longest_subarray_of_k_sum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0, ans = 0;
    unordered_map<int, int> mp; 
    mp[0] = -1;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(mp.count(sum - k)) {
            ans = max(ans, i - mp[sum - k]);
        }
        if(!mp.count(sum)) { // First occurence of idx
            mp[sum] = i;
        }
    }
    return ans;
}

// SLIDING WINDOW => For positive numbers only
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