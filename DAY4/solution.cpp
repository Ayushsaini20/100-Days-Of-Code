class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> ans;
        sort(arr.begin(), arr.end());
        int i = 0;
        int size = arr.size();  // Fix: Use arr.size() instead of undeclared size
        while (i < size) {
            int count = 1;
            for (int j = i + 1; j < size; j++) {  // Fix: Change j== to j++
                if (arr[i] == arr[j]) {
                    count++;
                } else {
                    break;
                }
            }
            ans.push_back(count);
            i = i + count;
        }
        size = ans.size();
        sort(ans.begin(), ans.end());
        for (int i = 0; i < size - 1; i++) {
            if (ans[i] == ans[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
