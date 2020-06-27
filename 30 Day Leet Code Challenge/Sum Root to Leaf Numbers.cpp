/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void solve(TreeNode *root,int val){
        int curr=10*val+root->val;
        if(!root->left && !root->right){
            ans+=curr;
            return;
        }
        if(root->left){
            solve(root->left,curr);
        }
        if(root->right){
            solve(root->right,curr);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(!root){
            return 0;
        }
        solve(root,0);
        return ans;
    }
};