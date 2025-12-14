vector<int> spiral_matrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    int r = 0, c = 0, d = 0;
    for(int i = 0; i < m * n; i++) {
        ans.push_back(matrix[r][c]);
        visited[r][c] = true;
    
        int nr = r + dirs[d].first;
        int nc = c + dirs[d].second;
    
        if(nr < 0 || nc < 0 || nr >= m || nc >= n || visited[nr][nc]) {
            d = (d + 1) % 4;
            nr = r + dirs[d].first;
            nc = c + dirs[d].second;
        }
    
        r = nr;
        c = nc;
    }
    
    return ans;
}
