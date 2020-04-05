class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0||n==1){
            return 0;
        }
        int **dp=new int*[n];
        for(int i=0;i<n;i++){
            dp[i]=new int[2];
        }
        dp[0][0]=0;
        dp[0][1]=(-1)*prices[0];
        dp[1][0]=max(0,dp[0][1]+prices[1]);
        dp[1][1]=max(dp[0][1],dp[0][0]-prices[1]);
        for(int i=2;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
        return 0;
    }
};