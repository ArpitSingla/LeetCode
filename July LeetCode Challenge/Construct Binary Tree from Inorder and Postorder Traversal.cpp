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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int pos,int poe,int ins,int ine){
        if(ins>ine){
            return NULL;
        }
        int rootData=postorder[poe];
        int index=-1;
        for(int i=ins;i<=ine;i++){
            if(rootData==inorder[i]){
                index=i;
                break;
            }
        }
        int lps=pos;
        int lis=ins;
        int lie=index-1;
        int lpe=lie-lis+lps;
        int rps=lpe+1;
        int rpe=poe-1;
        int ris=index+1;
        int rie=ine;
        TreeNode *root=new TreeNode(rootData);
        root->left=solve(inorder,postorder,lps,lpe,lis,lie);
        root->right=solve(inorder,postorder,rps,rpe,ris,rie);
        return root;
    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        return solve(inorder,postorder,0,n-1,0,n-1);
    }
};