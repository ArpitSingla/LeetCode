class Solution {
public:
    //Using STL next_permutation
    vector<vector<int>> permuteUnique(vector<int>& nums) {  
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        result.push_back(nums);
        while(next_permutation(nums.begin(),nums.end())){
            result.push_back(nums);
        }
        return result;
    }

    // Using Backtracking
    void rec(vector<vector<int>> &result,vector<int> &temp,vector<int>& nums,vector<bool> &used){
        if(temp.size()==nums.size()){
            result.push_back(temp);    
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            if(i>0&&nums[i]==nums[i-1]&&!used[i-1]){
                continue;
            }
            used[i]=true;
            temp.push_back(nums[i]);
            rec(result,temp,nums,used);
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        rec(result,temp,nums,used);
        return result;
    }
};