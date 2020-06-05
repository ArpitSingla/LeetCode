class Solution {
public:
    void rec(vector<vector<int>> &result,int start,int target,vector<int> &temp,vector<int> &candidates){
        if(target<0){
            return;
        }
        if(target==0){
            result.push_back(temp);
            return;
        }
        else{
            for(int i=start;i<candidates.size();i++){
                if(candidates[i]>target){
                    return;
                }
                if(i&&candidates[i]==candidates[i-1]&&i>start){
                    continue;
                }
                temp.push_back(candidates[i]);
                rec(result,i+1,target-candidates[i],temp,candidates);
                temp.pop_back();
            }    
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        rec(result,0,target,temp,candidates);
        return result;
    }
};