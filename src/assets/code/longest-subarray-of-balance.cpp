// nums is binary
// Here Balanced means subarray having equal count of 0s & 1s
int longest_subarray_with_balance(vector<int>& nums) {
    int n = nums.size();
    int ans = 0, b = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for(int i = 0; i < n; i++) {
        nums[i] ? b++ : b--;
        if(mp.count(b)) {
            ans = max(ans, i - mp[b]);
        }
        if(!mp.count(b)) { // First occurence
            mp[b] = i;
        }
    }
    return ans;
}

// Applications:
// https://leetcode.com/problems/contiguous-array/