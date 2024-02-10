class Solution 
{
private:
    string t;
    int check(int l, int r, int ans = 0)
    {
        while(l >= 0 and r <= t.size())
        {
            if(t[l--] == t[r++]) ans++;
            else break;
        }
        return ans;
    }
public:
    int countSubstrings(string s) 
    {
        int n = size(s), ans = 0;t = s;
        for(int i = 0; i < n; i++)
        {
            ans += check(i,i);    // odd length palindromes
            ans += check(i,i+1); // even length palindromes
        }
        return ans;
    }
};
