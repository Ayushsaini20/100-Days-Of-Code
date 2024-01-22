class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1, missing = 1;
        vector<int> result;

        for (auto x : nums) {
            if (nums[abs(x) - 1] < 0) {
                dup = abs(x);
            } else {
                nums[abs(x) - 1] *= -1;
            }
        }
        result.push_back(dup);

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }
        result.push_back(missing);

        return result;
    }
};
