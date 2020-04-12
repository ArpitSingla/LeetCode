class Solution {
public:
    int maxDiameter = 0;
    int getDiameterByRoot(TreeNode* root, int rootD) {
        if (root == NULL){
            return rootD-1;    
        } 
        int l = getDiameterByRoot(root->left, rootD+1);
        int r = getDiameterByRoot(root->right, rootD+1);
        maxDiameter = max( ((l-rootD)+(r-rootD)) , maxDiameter);
        return rootD + max( (l-rootD) , (r-rootD) );
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        getDiameterByRoot(root, 0);
        return maxDiameter;
    }
};