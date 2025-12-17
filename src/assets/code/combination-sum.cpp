vector<vector<int>> combination_sum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;

    function<void(int, int, vector<int>&)> dfs = [&](int i, int sum, vector<int>& temp) -> void {
        if(i >= n) {
            if(sum == target) {
                ans.push_back(temp);
            }
            return;
        }

        sum += nums[i];
        temp.push_back(nums[i]);
        dfs(i + 1, sum, temp);
        temp.pop_back();
        sum -= nums[i];

        dfs(i + 1, sum, temp);
    };
    
    vector<int> temp;
    dfs(0, 0, temp);
    return ans;
}