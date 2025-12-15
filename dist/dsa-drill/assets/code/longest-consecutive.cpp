int longest_consecutive(vector<int>& nums) {
    int ans = 0;
    unordered_set<int> set(nums.begin(), nums.end());
    for(int num : set) {
        int count = 0;
        if(!set.count(num - 1)) {
            count = 1;
            while(set.count(++num)) {
                count++;
            }
        }
        
        ans = max(ans, count);
    }

    return ans;
}