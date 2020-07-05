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
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            pair<int,int> p;
            p.first=0;
            p.second=0;
            return p;
        }
        pair<int,int> lp=solve(root->left);
        pair<int,int> rp=solve(root->right);
        int ht=1+max(lp.first,rp.first);
        int dt=max((lp.first+rp.first),max(lp.second,rp.second));
        pair<int,int> p;
        p.first=ht;
        p.second=dt;
        return p;
    } 
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> output=solve(root);
        return output.second;
    }
};