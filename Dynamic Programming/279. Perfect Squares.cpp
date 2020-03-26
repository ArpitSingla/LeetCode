class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        for(int i = 1;i<=n;i++) {
            dp[i] = i;
            for(int j = 2;j<=sqrt(i);j++) {
                dp[i] = min(dp[i], 1+ dp[i-j*j]);
            }
        }
        return dp[n];
    }
};