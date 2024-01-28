class Solution {
private:
    const int mod=int(1e9+7);
    int dp[1001][1001];
    int f(int n,int k) {
        //base case
        if(k<=0) return k==0;
        if(dp[n][k]!=-1) return dp[n][k];


        int ans=0;
        for(int i=0;i<n;++i) {
            ans+=f(n-1,k-i);
            ans%=mod;
        }
        return dp[n][k]=ans;
    }
public:
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,k);
    }
};
