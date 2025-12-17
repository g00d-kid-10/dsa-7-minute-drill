vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size(), n = image[0].size();
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
    int target_color = image[sr][sc];

    function<void(int, int)> dfs = [&](int r, int c) {
        if(target_color == color) return;
        if(r < 0 || c < 0 || r >= m || c >= n || image[r][c] != target_color) return;
        image[r][c] = color;
        for(auto [dr, dc] : dirs) {
            dfs(r + dr, c + dc);
        }
    };

    dfs(sr, sc);
    return image;
}