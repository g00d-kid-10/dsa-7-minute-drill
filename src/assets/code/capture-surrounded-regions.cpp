// surrounded region means they contains 'O' and not touching the border.

void capture_surrounded_regions(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<bool>> visited(m, vector<bool>(n));
    
    function<void(int, int)> mark_border = [&](int r, int c) -> void {
        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] == 'X' || visited[r][c]) return;
        visited[r][c] = true;
        for(auto[dr, dc] : dirs) {
            mark_border(r + dr, c + dc);
        }
    };

    function<void(int, int)> dfs = [&](int r, int c) -> void {
        if(r < 0 || c < 0 || r >= m || c >= n || board[r][c] == 'X' || visited[r][c]) return;
        board[r][c] = 'X';
        for(auto[dr, dc] : dirs) {
            dfs(r + dr, c + dc);
        }
    };

    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            if(!(r > 0 && c > 0 && r < m - 1 && c < n - 1)) {
                mark_border(r, c);
            }
        }
    }

    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            dfs(r, c);
        }
    }
}