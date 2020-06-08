class Solution {
public:
    void rec(vector<vector<int>> &res,vector<int> &temp,int *arr,int n,int k,int start){
        if(temp.size()==k){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<n;i++){
            temp.push_back(arr[i]);
            rec(res,temp,arr,n,k,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            arr[i]=i+1;
        }
        vector<vector<int>> res;
        vector<int> temp;
        rec(res,temp,arr,n,k,0);
        return res;
    }
};