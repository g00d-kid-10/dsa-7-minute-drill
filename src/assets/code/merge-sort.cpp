vector<int> sortArray(vector<int>& nums) {

    function<vector<int>(vector<int>&, vector<int>&)> merge = [&](vector<int>& left, vector<int>& right) -> vector<int> {
        int i = 0, j = 0, n = left.size(), m = right.size();
        vector<int> ans;
        while(i < n && j < m) left[i] < right[j] ? ans.push_back(left[i++]) : ans.push_back(right[j++]);
        while(i < n) ans.push_back(left[i++]);
        while(j < m) ans.push_back(right[j++]);
        return ans;
    };

    function<vector<int>(int, int)> merge_sort = [&](int l, int r) -> vector<int> {
        if(l == r) {
            return {nums[l]};
        }

        int m = l + (r - l) / 2;
        vector<int> left = merge_sort(l, m);
        vector<int> right = merge_sort(m + 1, r);
        return merge(left, right);
    };
    
    return merge_sort(0, nums.size() - 1);
}