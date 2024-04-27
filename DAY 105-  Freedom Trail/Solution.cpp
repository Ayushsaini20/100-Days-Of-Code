class Solution {
public:
    int r, k;
    vector<char> pos[26];
    int dp[200][200];
    void compute_pos(string& ring){
        // build the array for pos[c-'a']
        for (int i=0; i<r; i++){
            pos[ring[i]-'a'].push_back(i);
        }
    }
    int f(int i, int j, string& ring, string& key){
        if (i==0) {//base case
            if (key[i]==ring[j]) 
                return dp[0][j]=min(j, r-j)+1;
            return dp[0][j]=1e9+7;
        }
        if (dp[i][j]!=INT_MAX) return dp[i][j];
        int ans=1e9+7;
        if (key[i]==ring[j]){
            for (int prev : pos[key[i-1]-'a']) {
                int step = abs(prev-j);
                step = min(step, r-step);
                // Update the minimum steps
                ans= min(ans, f(i-1, prev, ring, key)+step+1);
            }
        }
        return dp[i][j]=ans;
    }
    int findRotateSteps(string& ring, string& key) {
        r=ring.size(), k=key.size();
        compute_pos(ring);
        fill(&(dp[0][0]), &(dp[0][0])+40000, INT_MAX);
        int ans=INT_MAX;
        for (int j: pos[key[k-1]-'a'])
            ans=min(ans, f(k-1, j, ring, key));       
        return ans;
    }
};
