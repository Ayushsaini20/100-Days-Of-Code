class Solution {
public:
    // Function to find the length of the longest common subsequence in two strings.
    int longestCommonSubsequence(string text1, string text2) {
        int text1Length = text1.size(), text2Length = text2.size();
        // Create a 2D array to store lengths of common subsequence at each index.
        int dp[text1Length + 1][text2Length + 1];
      
        // Initialize the 2D array with zero.
        memset(dp, 0, sizeof dp);
      
        // Loop through both strings and fill the dp array.
        for (int i = 1; i <= text1Length; ++i) {
            for (int j = 1; j <= text2Length; ++j) {
                // If current characters match, add 1 to the length of the sequence
                // until the previous character from both strings.
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // If current characters do not match, take the maximum length
                    // achieved by either skipping the current character of text1 or text2.
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
      
        // Return the value in the bottom-right cell which contains the
        // length of the longest common subsequence for the entire strings.
        return dp[text1Length][text2Length];
    }
};
