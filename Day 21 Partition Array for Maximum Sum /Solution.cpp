class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(k,0);
        for(int idx=n-1;idx>=0;--idx) {
            int ans=0,maxi=0;
            int lim=min(idx+k,n);
            for(int i=idx;i<lim;++i) {
                maxi=max(maxi,arr[i]);
                ans=max(ans, maxi*(i-idx+1) + dp[(i+1)%k]);
            }
            dp[idx%k]=ans;
        }
        return dp[0];
    }
};
