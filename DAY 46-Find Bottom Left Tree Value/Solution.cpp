class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> levelQue;
        levelQue.push(root);
        int leftNodeVal = root->val;
        while(!levelQue.empty()){
            int currLevelSize = levelQue.size();
            int orgSize = currLevelSize;
            while(currLevelSize-->0){
                TreeNode * currNode = levelQue.front();
                levelQue.pop();
                if(orgSize-1 == currLevelSize)
                    leftNodeVal = currNode->val;
                if(currNode->left != NULL)levelQue.push(currNode->left);
                if(currNode->right != NULL)levelQue.push(currNode->right);
            }
        }   
        return leftNodeVal;
    }
};
