class Solution {
public:
    void solve(vector<int>& nums,int i,vector<vector<int>> &result,vector<int> &temp){
        result.push_back(temp);
        for(int j=i;j<nums.size();j++){
            temp.push_back(nums[j]);
            solve(nums,j+1,result,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(nums,0,result,temp);
        return result;
    }
};