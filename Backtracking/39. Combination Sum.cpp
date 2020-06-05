class Solution {
public:
    void rec(vector<int>& candidates, int target, vector<vector<int>> &result,vector<int> &temp,int start){
        if(target<0){
            return;
        }
        if(target==0){
            result.push_back(temp);
        }
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            rec(candidates,target-candidates[i],result,temp,i);
            temp.pop_back();
        }        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        rec(candidates,target,result,temp,0);
        return result;
    }
};