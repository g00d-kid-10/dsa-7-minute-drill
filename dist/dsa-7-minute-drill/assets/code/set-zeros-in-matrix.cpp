void set_zeros_in_matrix(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> rows(m, 1), cols(n, 1);
    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            if(matrix[r][c] == 0) {
                rows[r] = 0; cols[c] = 0;
            }
        }
    }

    for(int r = 0; r < m; r++) {
        for(int c = 0; c < n; c++) {
            if(rows[r] * cols[c] == 0) {
                matrix[r][c] = 0;
            }
        }
    }
}