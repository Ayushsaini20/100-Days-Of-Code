class Solution {
public:
    bool isIsomorphic(string& s, string& t) {      
        int n=s.size();
        unordered_map<char, char> st, ts;
        for(int i=0; i<n; i++){
            char cs=s[i], ct=t[i];
            if (st.count(cs)==0 && ts.count(ct)==0){
                st[cs]=ct;
                ts[ct]=cs;
            } 
            else{
                if(st[cs]!=ct || ts[ct]!=cs) return 0;
            } 
        }
        return 1;
    }
};
