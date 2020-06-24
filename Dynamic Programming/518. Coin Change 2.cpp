class Solution {
public:
    // Using Recursion
    int solve(int amount, vector<int>& coins,int n,vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][amount]!=-1){
            return dp[n][amount];
        }
        if(coins[n-1]>amount){
            dp[n][amount]=solve(amount,coins,n-1,dp);
        }
        else{
            dp[n][amount]=solve(amount,coins,n-1,dp)+solve(amount-coins[n-1],coins,n,dp);    
        }
        return dp[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(amount,coins,n,dp);
    }

    // Using 2D Array
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                dp[i][j]=dp[i-1][j];
                if(coins[i-1]<=j){
                    dp[i][j]+=dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];
    }

    // Using ID Array
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j){
                    dp[j]+=dp[j-coins[i]];
                }
            }
        }
        return dp[amount];
    }
};