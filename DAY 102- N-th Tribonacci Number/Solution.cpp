class Solution {
public:
    int t[38];
    constexpr int f(int n){
        if (t[n]!=-1) return t[n];
        switch(n){
            case 0: return t[n]=0;
            case 1: case 2: return t[n]=1;
            default: return t[n]=f(n-3)+f(n-2)+f(n-1);
        }
    }
    int tribonacci(int n) {
        fill(t, t+38, -1);
        return f(n);
    }
};
