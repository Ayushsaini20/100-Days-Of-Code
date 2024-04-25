class Solution {
public:
    int longestIdealString(string& s, int k) {
        int seq[26]={0};// max len of seq ending at char(i+'a')
        int ans=0;
        for(char c: s){
            int i=c-'a';
            int j0=max(0, i-k),  j1=min(i+k, 25);
            for(int j=j0; j<=j1; j++)
                seq[i]=max(seq[i], seq[j]);//longest seq ending at char(j+'a')
            seq[i]++;//Put c to the tail
        }
        return *max_element(seq, seq+26);   
    }
};
