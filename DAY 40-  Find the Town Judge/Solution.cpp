class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int trusting[1001]={0}, trusted[1001]={0};//1 <= n <= 1000
        for (vector<int>& e: trust){
            trusting[e[0]]++; //outdeg
            trusted[e[1]]++; // indeg
        }
        for(int i=1; i<=n; i++)
            if (trusting[i]==0 && trusted[i]==n-1) return i;
        return -1;      
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
