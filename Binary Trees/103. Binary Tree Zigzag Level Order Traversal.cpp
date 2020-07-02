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
    // Using 2 Stacks
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(s1.size()!=0 || s2.size()!=0){
            vector<int> temp1,temp2;
            while(s1.size()!=0){
                TreeNode *temp=s1.top();
                s1.pop();
                temp1.push_back(temp->val);
                if(temp->left!=NULL){
                    s2.push(temp->left);
                }
                if(temp->right!=NULL){
                    s2.push(temp->right);
                }
            }
            while(s2.size()!=0){
                TreeNode *temp=s2.top();
                s2.pop();
                temp2.push_back(temp->val);
                if(temp->right!=NULL){
                    s1.push(temp->right);
                }
                if(temp->left!=NULL){
                    s1.push(temp->left);
                }
            }
            if(temp1.size()!=0){
                 ans.push_back(temp1);    
            }
            if(temp2.size()!=0){
                ans.push_back(temp2);    
            }
        }
        return ans;
    }
    // Using Queue
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return vector<vector<int> > ();
        }
        vector<vector<int> > result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while ( !nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : (size - 1 - i);

                row[index] = node->val;
                if (node->left) {
                    nodesQueue.push(node->left);
                }
                if (node->right) {
                    nodesQueue.push(node->right);
                }
            }
            // after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};