class Solution {
public:
    //Using Recursive DP
     int solve(string s1, string s2,int n,int m,vector<vector<int>> &dp){
        if(n==0 && m==0){
            return 0;
        }
        if(n==0){
            return accumulate(s2.begin(),s2.end(),0);
        }
        if(m==0){
            return accumulate(s1.begin(),s1.end(),0);
        }
        if(dp[n][m]!=-1){
            return dp[n][m];
        }
        if(s1[0]==s2[0]){
            dp[n][m]=solve(s1.substr(1),s2.substr(1),n-1,m-1,dp);
        }
        else{
            dp[n][m]=min(solve(s1.substr(1),s2,n-1,m,dp)+s1[0],solve(s1,s2.substr(1),n,m-1,dp)+s2[0]);
        }
        return dp[n][m];
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(s1,s2,n,m,dp);
    }
    
    //Iterative DP
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            dp[i][0]=dp[i-1][0]+s1[i-1];
        }
        for(int i=1;i<=m;i++){
            dp[0][i]=dp[0][i-1]+s2[i-1];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
                }
            }
        }
        return dp[n][m];
    }
};