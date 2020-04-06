class Solution {
public:
    int integerBreak(int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,1));
        for(int i = 2;i<n;i++) {
            for(int j = 1;j<=n;j++) {
                dp[i][j] = dp[i-1][j];
                if(j>=i) {
                    dp[i][j] = max(dp[i][j],i*dp[i][j-i]);
                }
            }
        }
        return dp[n-1][n];
    }
};