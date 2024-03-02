class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> t;
        for (int i = 0; i < nums.size(); i++)
            t.push_back(nums[i] * nums[i]);             // Square each element.
        sort(t.begin(), t.end());                  // Sort the squared values.
        return t;                                      // Return the sorted squares.
    }
};
