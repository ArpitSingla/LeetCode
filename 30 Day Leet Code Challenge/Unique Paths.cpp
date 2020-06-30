class Solution {
public:

    //Using Recursion
    int uniqueWays(int m,int n,int **dp){
        if(m==0 && n==0){
            return 0;
        }
        if(m==1 || n==1){
            return 1;
        }
        if(dp[m][n]>0){
            return dp[m][n];
        }
        dp[m][n]=uniqueWays(m,n-1,dp)+uniqueWays(m-1,n,dp);
        return dp[m][n];
    }

    // Using DP
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n+1,vector<int>(m+1,1));
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};