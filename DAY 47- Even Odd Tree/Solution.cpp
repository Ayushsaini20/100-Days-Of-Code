class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        TreeNode* current = root;
        return dfs(current, 0);
    }

private:
    vector<int> prev;
    bool dfs(TreeNode* current, size_t level) {
        // Base case, an empty tree is Even-Odd
        if (current == nullptr) {
            return true;
        }

        // Compare the parity of current and level
        if (current->val % 2 == level % 2) {
            return false;
        }

        // Resize prev to make room for the new level
        prev.resize(max(prev.size(), level + 1));

        // If there are previous nodes on this level, check increasing/decreasing
        // If on an even level, check that currrent's value is greater than the previous on this level
        // If on an odd level, check that current's value is less than the previous on this level
        if (prev[level] != 0 && 
                ((level % 2 == 0 && current->val <= prev[level]) ||
                 (level % 2 == 1 && current->val >= prev[level]))) {
            return false;  // Not in the required order
        }

        // Add current value to prev at index level
        prev[level] = current->val;

        // Recursively call DFS on the left and right children
        return dfs(current->left, level + 1) && dfs(current->right, level + 1);
    }
};
