#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int openLock(vector<string>& deadends, const string& target) {
        bool seen[10000]={0};// 0000~9999
        for(string& s: deadends){
            seen[stoi(s)]=1;
        }
        if (seen[0]) return -1;//edge case
        queue<pair<int,string>> q;
        q.emplace(0, "0000");
        seen[0]=1;
        while(!q.empty()){
            auto [turn, s]=q.front(); q.pop();
        //    cout<<turn<<":"<<s<<endl;
            if (s==target) return turn;
            for(int d=0; d<4; d++){// 8 ways of turning
                for(int i=-1; i<=1; i+=2){
                    string t=s;
                    char& move=t[d];
                    move=(move-'0'+i+10)%10+'0';
                    int x=stoi(t);
                    if (!seen[x]) {
                        q.emplace(turn+1, t);
                        seen[x]=1;
                    }
                }
            }
        }
        return -1;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
