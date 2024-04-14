class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        queue<pair<TreeNode*, bool>> q;  // (node, is_left)
        q.push({root, false});
        int totalSum = 0;
        
        while (!q.empty()) {
            auto [node, isLeft] = q.front();
            q.pop();
            
            if (isLeft && !node->left && !node->right) {
                totalSum += node->val;
            }
            
            if (node->left) {
                q.push({node->left, true});
            }
            if (node->right) {
                q.push({node->right, false});
            }
        }
        
        return totalSum;
    }
};
