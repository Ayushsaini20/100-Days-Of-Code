class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long perimeter = accumulate(nums.begin(), nums.end(), 0LL);

        for (int i = 0; i < nums.size() - 2; i++) {
            make_heap(nums.begin() + i, nums.end());
            int longestSide = nums[i];
            if (perimeter > (longestSide << 1)) return perimeter; // Effectively the same as perimeter - longestSide > longestSide
            perimeter -= longestSide;
        }
        return -1;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
