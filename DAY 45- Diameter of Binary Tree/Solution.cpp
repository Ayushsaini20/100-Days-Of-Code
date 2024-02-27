class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        findDia(root);
        return maxDia;
    }
private:
    int maxDia = 0;
    int findDia(TreeNode* root){
        if(root == NULL)return 0;
        int leftDepth = findDia(root->left);
        int rightDepth = findDia(root->right);
        int currDia = leftDepth + rightDepth;
        maxDia = max(maxDia, currDia);
        return 1 + max(leftDepth, rightDepth);
    }
};
