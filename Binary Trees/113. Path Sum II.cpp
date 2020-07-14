/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int sum,vector<vector<int>> &ans,vector<int> &temp){
        if(root==NULL){
            return;
        }
        temp.push_back(root->val);
        if(root->left==NULL && root->right==NULL && root->val==sum){
            ans.push_back(temp);
        }
        solve(root->left,sum-root->val,ans,temp);
        solve(root->right,sum-root->val,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(root,sum,ans,temp);
        return ans;
    }
};