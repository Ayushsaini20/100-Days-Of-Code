class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result; // Result vector to store duplicate numbers
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; // Get the index corresponding to the number
            if (nums[index] < 0) { // If the number at index is negative, it means it's seen before
                result.push_back(index + 1); // Add the duplicate number to the result
            } else {
                nums[index] = -nums[index]; // Mark the number as seen by negating it
            }
        }
        return result; // Return the vector containing duplicate numbers
    }
};
