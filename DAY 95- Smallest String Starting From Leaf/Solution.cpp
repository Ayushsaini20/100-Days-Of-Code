class Solution {
public:
    string finalans;
    void solve(TreeNode *root,string z){
        char ch = root->val+'a';
        if(root->left == NULL && root->right == NULL){
            if(finalans.size()==0) finalans=ch+z;
            else if(ch+z < finalans) finalans = ch+z;
            return;
        }
        if(root->left) solve(root->left,ch+z);
        if(root->right) solve(root->right,ch+z);
    }
    string smallestFromLeaf(TreeNode* root) {
        string z="";
        finalans = "";
        solve(root,z);
        return finalans;
    }
};
