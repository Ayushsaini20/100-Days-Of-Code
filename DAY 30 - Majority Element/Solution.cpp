class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;

        for(int val : nums) {
            map[val]++;
        }

        for(auto& pair : map) {
            int freq = pair.second;
            if(freq > n / 2) {
                return pair.first;
            }
        }
        return -1;
    }
};
