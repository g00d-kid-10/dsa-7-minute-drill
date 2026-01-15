/**
 *  https://leetcode.com/problems/maximum-matrix-sum/description/
    
    1975. Maximum Matrix Sum
    You are given an n x n integer matrix. You can do the following operation any number of times:
    Choose any two adjacent elements of matrix and multiply each of them by -1.
    Two elements are considered adjacent if and only if they share a border.
    Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.
*/

long long max_matrix_sum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int neg = 0, pos = 0, minimum = INT_MAX;
    long long ans = 0;
    for(int r = 0; r < n; r++) {
        for(int c = 0; c < n; c++) {
            int val = matrix[r][c];
            val <= 0 ? neg++ : pos++;
            ans += abs(val);
            minimum = min(minimum, abs(val));
        }
    }

    return (neg % 2 == 0) ? ans : ans - 2 * minimum;
}