vector<int> two_sum(vector<int>& nums, int target_sum) {
    int n = nums.size();
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) mp[nums[i]] = i;
    
    for(int i = 0; i < n; i++) {
        int target = target_sum - nums[i]; 
        if(mp.count(target) && mp[target] != i) {
            return {i, mp[target]};
        }
    }

    return {-1, -1};
}