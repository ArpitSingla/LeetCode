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
int count(TreeNode *root)
{
    if(root==NULL)
        return 0;

    if(root->left ==NULL && root->right==NULL)
        return 1;

    return count(root->left) + count(root->right)+1;
}

void find(TreeNode *root,int k,int &value)
{
    if(root==NULL)
        return;

    int x = count(root->left);

    if(x==k-1)
    {
        value = root->val;
        return;
    }   

    else if(x>k-1)
        find(root->left,k,value);
    else if(x<k-1)
        find(root->right,k-x-1,value);

    return;
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        int value =0;

        find(root,k,value);
        return value;

    }
}; 