class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        for (int i = 0; i < size; ++i) {
            int first_pos = s.find(s[i]);
            int last_pos = s.find_last_of(s[i]);
            if (first_pos == last_pos) {
                return i;
            }
        } 
        return -1;
    }
};
