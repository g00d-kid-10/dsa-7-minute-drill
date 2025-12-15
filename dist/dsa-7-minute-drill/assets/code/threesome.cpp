vector<vector<int>> threesome(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    
    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i - 1] == nums[i]) continue;
        
        int j = i + 1;
        int k = n - 1;
        while(j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if(sum < 0) {
                j++;
            } else if(sum > 0) {
                k--;
            } else {
                ans.push_back({nums[i], nums[j++], nums[k--]});
                while(nums[j - 1] == nums[j]) j++;
                while(nums[k] == nums[k + 1]) k--;
            }
        }
    }

    return ans;
}
