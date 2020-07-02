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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        stack<vector<int>> s;
        q.push(root);
        while(q.size()!=0){
            int count=q.size();
            vector<int> temp;
            while(count--){
                TreeNode *front=q.front();
                q.pop();
                temp.push_back(front->val);
                if(front->left!=NULL){
                    q.push(front->left);
                }
                if(front->right!=NULL){
                    q.push(front->right);
                }
            }
            s.push(temp);
        }
        while(s.size()!=0){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};