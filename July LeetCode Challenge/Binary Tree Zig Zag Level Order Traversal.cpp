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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int> > ();
        }
        vector<vector<int> > ans;
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(q.size()!=0){
            int count=q.size();
            vector<int> tempv;
            while(count--){
                TreeNode *temp=q.front();
                q.pop();
                tempv.push_back(temp->val);
                if(temp->left!=NULL){
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                }
            }
            if(!leftToRight){
                reverse(tempv.begin(),tempv.end());
            }
            ans.push_back(tempv);
            leftToRight=!leftToRight;
        }
        return ans;
    }
};