// https://leetcode.com/problems/contiguous-array/

// Here Balanced means subarray having equal count of 0s & 1s
int findMaxLength(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    int count = 0;
    unordered_map<int, int> mp; mp[0] = -1;
    for(int i = 0; i < n; i++) {
        nums[i] ? count++ : count--;
        if(mp.count(count)) {
            ans = max(ans, i - mp[count]);
        } else {
            mp[count] = i;
        }
    }

    return ans;
}