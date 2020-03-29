class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0){
            return -1;
        }
        vector<int> dp(amount+1,INT_MAX);
        sort(coins.begin(),coins.end());
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    if(dp[i-coins[j]]!=INT_MAX){
                        dp[i]=min(dp[i],dp[i-coins[j]]+1);
                    }
                }
                else{
                    break;
                }
            }
        }
        if(dp[amount]==INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};
