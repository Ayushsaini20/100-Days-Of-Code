class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true; // If both nodes are null, return true
        if (!p || !q) return false; // If one node is null in either p or q, return false
		 //Check if the values of p and q are the same, then recursively check left and right subtrees
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
