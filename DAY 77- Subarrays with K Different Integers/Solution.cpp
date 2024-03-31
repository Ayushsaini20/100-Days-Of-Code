class Solution {
public:
    int subarraysWithKDistinct(std::vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }

    int subarraysWithAtMostKDistinct(std::vector<int>& nums, int k) {
        int ans = 0;
        std::vector<int> count(nums.size() + 1, 0);

        int l = 0;
        for (int r = 0; r < nums.size(); ++r) {
            if (++count[nums[r]] == 1)
                --k;
            while (k == -1) {
                if (--count[nums[l++]] == 0)
                    ++k;
            }
            ans += r - l + 1; 
        }
        return ans;
    }
};
