class Solution {
public:
    int pseudoPalindromicPaths(TreeNode* root) {
        int count = 0, path = 0;

        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 0});

        while (!stk.empty()) {
            auto [node, path] = stk.top();
            stk.pop();

            if (node != nullptr) {
                
                path = path ^ (1 << node->val);

                
                if (node->left == nullptr && node->right == nullptr) {
                    
                    if ((path & (path - 1)) == 0) {
                        ++count;
                    }
                } else {
                    stk.push({node->right, path});
                    stk.push({node->left, path});
                }
            }
        }

        return count;
    }
};
