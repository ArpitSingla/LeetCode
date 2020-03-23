class Solution {
public:
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
    
    int uniquePaths(int m, int n) {
        int **dp=new int*[m+1];
        for(int i=0;i<=m;i++){
            dp[i]=new int[n+1];
        }
        return uniqueWays(m,n,dp);
    }
};