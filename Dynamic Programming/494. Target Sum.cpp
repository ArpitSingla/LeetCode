class Solution {
public:
    int solve(vector<int>& nums, int S,int sum,int i,vector<vector<int>>& dp){
        if(i==nums.size()){
            if(sum==S){
                return 1;
            }
            return 0;
        }
        if(dp[i][sum+1000]!=INT_MIN){
            return dp[i][sum+1000];
        }
        dp[i][sum+1000]=solve(nums,S,sum-nums[i],i+1,dp)+solve(nums,S,sum+nums[i],i+1,dp);
        int ans=dp[i][sum+1000];
        return ans;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum=0;
        int i=0;
        int s=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(s+1001,INT_MIN));
        return solve(nums,S,sum,i,dp);
    }
};