class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<int> v;
        for(int i=0;i<n-1;i++){
            v.push_back(nums[i+1]-nums[i]);
        }
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=1;
        dp[0][1]=1;
        for(int i=1;i<n;i++){
            if(v[i-1]>0){
                dp[i][1]=max(dp[i-1][0]+1,dp[i-1][1]);
            }
            else if(v[i-1]<0){
                dp[i][0]=max(dp[i-1][0],dp[i-1][1]+1);
            }
            else{
                dp[i][0]=dp[i-1][0];    
                dp[i][1]=dp[i-1][1]; 
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};