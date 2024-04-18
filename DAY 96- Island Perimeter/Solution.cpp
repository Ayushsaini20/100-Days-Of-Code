class Solution {
public:
    const int di[4]={1,-1,0,0};
    const int dj[4]={0,0,1,-1};
    int cnt=0;
    int n, m;
    void dfs(int i ,int j ,vector<vector<int>>& grid){
        if (i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) { 
            cnt++; 
            return ; 
        }
        if (grid[i][j]!=1) return;
        grid[i][j]=2;
        for ( int k=0; k<4; k++){
            int r=i+di[k], s=j+dj[k];
            dfs(r, s, grid);
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        for (int i=0; i<n; i++) 
            for (int j=0; j<m; j++) 
                if (grid[i][j]){// starting cell
                    dfs(i,j, grid ) ;
                    goto done;//evil but easiest way 
                }
        done:
        return cnt;
    }
};



auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
