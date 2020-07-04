/*
Recursion is not good way to go due to performance overhead and risk to run it against huge tree. With standard queue solution looks simple robust and runs faster.
*/
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0){
            TreeNode *front=q.front();
            q.pop();
            TreeNode *temp=front->left;
            front->left=front->right;
            front->right=temp;
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
        return root;
    }
}; 