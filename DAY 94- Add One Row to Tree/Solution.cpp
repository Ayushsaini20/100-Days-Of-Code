class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth==1){
            TreeNode* ptr=new TreeNode(val);
            ptr->left=root;
            return ptr;
        }
        vector<pair<TreeNode*,int>> stack={{root, 1}};
        while(!stack.empty()){
            auto [node, level]=stack.back();
            stack.pop_back();
            if (level==depth-1){
                TreeNode* ptr=node->left;
                node->left=new TreeNode(val);
                node->left->left=ptr;

                ptr=node->right;
                node->right=new TreeNode(val);
                node->right->right=ptr;
            }
            else{
                if (node->right) stack.emplace_back(node->right, level+1);
                if (node->left) stack.emplace_back(node->left, level+1);
            }
        }
        return root;
    }
};
