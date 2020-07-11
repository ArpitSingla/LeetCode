class Solution {
public:

    // Using Approach used in Two Sum problem
    // Time-O(n)  Space-O(n)
    void inorder(TreeNode *root,vector<int> &ans){
        if(root==NULL){
            return;
        }    
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root,ans);
        int l=0,r=ans.size()-1;
        for(int i=0;i<ans.size()-1;i++){
            int sum=ans[l]+ans[r];
            if(sum==k){
                return true;
            }
            else if(sum>k){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }

    // Using set Approach
    // Time-O(n)  Space-O(n)
    bool search(TreeNode *root,int k,unordered_set<int> &s){
        if(root==NULL){
            return false;
        }    
        if(s.find(k-root->val)!=s.end()){
            return true;
        }
        s.insert(root->val);
        return search(root->left,k,s)||search(root->right,k,s);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return search(root,k,s);
    }
};