class Solution {
public:
    void rec(vector<vector<int>> &result,vector<int> &temp,vector<int>& nums){
        if(temp.size()==nums.size()){
            result.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(count(temp.begin(),temp.end(),nums[i])){
                continue;
            }
            temp.push_back(nums[i]);
            rec(result,temp,nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        rec(result,temp,nums);
        return result;
    }
};