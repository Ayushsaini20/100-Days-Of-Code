class Solution {
public:
    // time/space: O(n ^ 1.5)/O(n)
    int numSquares(int n) {
        // find all perfect squares that are not bigger than `n`
        vector<int> squares;
        for (int x = 1; (1LL * x * x) <= n; x++) squares.push_back(x * x);

        // dynamic programming
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (auto& square : squares) {
                if ((i - square) >= 0) dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }
        return dp[n];
    }
};
