void transpose(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for(int r = 0; r < m; r++) {
        for(int c = r; c < n; c++) {
            swap(matrix[r][c], matrix[c][r]);
        }
    }
}
void h_flip(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n / 2; c++) {
            swap(matrix[r][c], matrix[r][m - 1 - c]);
        }
    }
}
void rotate_square_grid(vector<vector<int>>& matrix) {
    transpose(matrix);
    h_flip(matrix);
}