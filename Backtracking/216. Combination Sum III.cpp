class Solution {
public:
    void rec(vector<vector<int>> &res,vector<int> &temp,vector<int> &arr,int n,int k,int start){
        if(n<=0){
            if(temp.size()==k){
                res.push_back(temp);
            }
            return;
        }
        for(int i=start;i<9;i++){
            if(arr[i]>n || count(temp.begin(),temp.end(),arr[i])){
                continue;
            }
            temp.push_back(arr[i]);
            rec(res,temp,arr,n-arr[i],k,i+1);
            temp.pop_back();
        }        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        vector<int> arr(9);
        for(int i=0;i<9;i++){
            arr[i]=i+1;
        }
        rec(res,temp,arr,n,k,0);
        return res;
    }
};