class Solution {
public:
int dp[51][51][51];
long long mod = 1e9+7;
int dfs(int i, int j, int n, int m, int moves)
{
    if(i<0 || i>=n || j<0 || j>=m)
    {
        return 1;
    }
    if(moves <= 0)return 0;
    if(dp[i][j][moves] != -1)return dp[i][j][moves];
    int up = dfs(i-1 , j , n , m , moves-1);
    int down = dfs(i+1 , j , n , m , moves-1);
    int left = dfs(i , j-1 , n , m , moves-1);
    int right = dfs(i , j+1 , n , m , moves-1);

    return dp[i][j][moves] = (up%mod + down%mod + left%mod + right%mod)%mod;
}
    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {       
        memset(dp , -1 , sizeof(dp));
        return dfs(startRow , startColumn , n , m , maxMove);
    }
};
