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
void find(TreeNode *root,int num,TreeNode **parent,int &depth,int curr)
{
    if(root==NULL)
    {
        return;
    }

    if(root->left!=NULL && root->left->val==num)
    {
        *parent = root;
        depth = curr+1;
        return;
    }
    if(root->right!=NULL && root->right->val==num)
    {
        *parent = root;
        depth = curr+1;
        return;
    }

    find(root->left,num,parent,depth,curr+1);
    find(root->right,num,parent,depth,curr+1);

    return;
}
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {

        TreeNode *parent1 = new TreeNode;
        TreeNode *parent2 = new TreeNode;
        int depth1,depth2;

        find(root,x,&parent1,depth1,0);

        find(root,y,&parent2,depth2,0);

        return (depth1==depth2 && parent1!=parent2);

    }
}; 