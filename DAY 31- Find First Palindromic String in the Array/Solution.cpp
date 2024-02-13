class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for( string& s : words){
            int n=s.size(), n_2=n>>1;
            bool isPal=1;
            for(int i=0; i<n_2; i++)
                if(s[i]!=s[n-1-i]){
                    isPal=0;
                    break;
                }
            if (isPal) return s;
        }
        return "";
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
