class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>Set;
        int Max=0;
        int start=0, end=0;
        while(start<s.size())
        {
            auto it = Set.find(s[start]);

            if(it==Set.end())
            {
                if(start-end+1 >Max)
                    Max= start - end+1;
                Set.insert(s[start]);
                start++;
            }
            else{
                Set.erase(s[end]);
                end++;
            }    
        }
        return Max;
    }
};
