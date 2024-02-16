class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        for (int& x : arr) {
            mp[x]++;
        }
        
        vector<int> freq;
        for (auto& pair : mp) {
            freq.push_back(pair.second);
        }
        sort(begin(freq), end(freq));
        int count = 0;
        for (int& f : freq) {
            if (k >= f) {
                k -= f;
                count++;
            } else {
                break;
            }
        }
        
        return freq.size() - count;
    }
};
