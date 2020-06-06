class Solution {
public:
    //Using Backtracking
    void rec(vector<vector<int>> &result,vector<int> &temp,vector<int>& nums,int start){
        result.push_back(temp);
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            rec(result,temp,nums,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        rec(result,temp,nums,0);
        return result;
    }

    //Using Bit Manipulation
     vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n=nums.size();
        int masks=1<<n;
        for(int i=0;i<masks;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                int p=1<<j;
                if(i&p){
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};