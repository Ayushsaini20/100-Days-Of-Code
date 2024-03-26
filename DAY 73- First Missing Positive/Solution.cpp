class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i) {
            if(nums[i] < 0) nums[i] = 0;
        }
        for(int i = 0; i < n; ++i) {
            int ind = abs(nums[i]) - 1;
            if(ind < 0 || ind >= n) continue;
            if(nums[ind] > 0) {
                nums[ind] *= -1;
            } else if(nums[ind] == 0) {
                nums[ind] = INT_MIN + 1;
            }
        }
        for(int i = 0; i < n; ++i) {
            if(nums[i] >= 0) return i + 1;
        }
        return n + 1;
    }
};
