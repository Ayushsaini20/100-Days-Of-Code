class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // Create a DP table to store minimum falling path sums
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        // Initialize the last row of DP table with the matrix values
        for (int j = 0; j < cols; ++j) {
            dp[rows - 1][j] = matrix[rows - 1][j];
        }

        // Build the DP table bottom-up
        for (int i = rows - 2; i >= 0; --i) {
            for (int j = 0; j < cols; ++j) {
                int op1 = (j > 0) ? dp[i + 1][j - 1] : INT_MAX;
                int op2 = dp[i + 1][j];
                int op3 = (j < cols - 1) ? dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(op1, min(op2, op3));
            }
        }

        // Find the minimum falling path sum in the first row of the DP table
        return *min_element(dp[0].begin(), dp[0].end());
    }
};
