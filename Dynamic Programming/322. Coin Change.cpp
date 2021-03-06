class Solution {
public:
    //Using 2D Array
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0){
            return 0;
        }
        vector<vector<unsigned int>> dp(n+1,vector<unsigned int>(amount+1,INT_MAX));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j>=coins[i-1]){
                    dp[i][j]=min(dp[i-1][j],1+dp[i][j-coins[i-1]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[n][amount]==INT_MAX?-1:dp[n][amount];
    }

    //Using 1D Array
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(amount==0){
            return 0;
        }
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int j=1;j<=amount;j++){
            for(auto i:coins){
                if(j>=i){
                    dp[j]=min(dp[j],1+dp[j-i]);
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};