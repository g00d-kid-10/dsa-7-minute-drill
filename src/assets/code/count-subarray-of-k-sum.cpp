// HASHMAP
int count_subarray_sum_equals_k(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0, ans = 0;
    unordered_map<int, int> mp;
    mp[0] = 1; // 
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        if(mp.count(sum - k)) {
            ans += mp[sum - k];
        }             
        mp[sum]++; // Sum frequency
    }
    return ans;
}

// PREFIX SUM
int count_subarray_sum_equals_k(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> pre_sum(n + 1);
    for(int i = 1; i < n + 1; i++) pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n + 1; j++) {
            int sum = pre_sum[j] - pre_sum[i];
            sum == k ? ans++ : ans;
        }
    }

    return ans;
}

// INSIGHTS: [HASMAP]
// Keep track of frequencies of sum occured and on each iteration look for how many compilments(sum - k) already existed
// because FROM all those indexes where this complement occured TO this current itteration index all((i.e. total no of frequency)) will form a subarray of sum k.
// Current iteration sum - previously occured compliment = k