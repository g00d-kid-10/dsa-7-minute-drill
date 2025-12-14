vector<vector<int>> merge_interval(vector<vector<int>>& intervals) {
    if(intervals.size() < 2) return intervals;
    
    vector<vector<int>> ans;
    vector<int> prev = {intervals[0][0], intervals[0][1]};
    int n = intervals.size();
    for(int i = 1; i < n; i++) {
        vector<int> curr = {intervals[i][0], intervals[i][1]};
        if(overlap_or_touch(pair<int, int>(prev[0], prev[1]), pair<int, int>(curr[0], curr[1]))) {
            vector<int> merged = {
                min(prev[0], curr[0]),
                max(prev[1], curr[1])
            };
            prev = merged;
            continue;
        }

        ans.push_back(prev);
        prev = curr;
    }

    ans.push_back(prev);
}