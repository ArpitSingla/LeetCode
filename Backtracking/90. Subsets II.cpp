class Solution {
public:
    //Using Backtracking
    void rec(vector<vector<int>> &result,vector<int> &temp,vector<int>& nums,int start,vector<bool> &used){
        result.push_back(temp);
        for(int i=start;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            if(i>0&&nums[i]==nums[i-1]&&used[i-1]==false){
                continue;
            }
            used[i]=true;
            temp.push_back(nums[i]);
            rec(result,temp,nums,i+1,used);
            temp.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        rec(result,temp,nums,0,used);
        return result;
    }

    //Using Bit Manipulation
     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int p=1<<n;
        for(int i=0;i<p;i++){
            int flag=0;
            vector<int> temp;
            for(int j=0;j<n;j++){
                int ans=1<<j;
                if(ans&i){
                    if(j>0 && nums[j]==nums[j-1]&&((1<<j-1)&i)==0){
                        flag=1;
                        break;
                    }
                    else{
                        temp.push_back(nums[j]);    
                    }
                }
            }
            if(flag==0){
                result.push_back(temp);    
            }
        }
        return result;
    }
};