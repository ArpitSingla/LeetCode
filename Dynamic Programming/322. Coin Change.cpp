class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        reverse(coins.begin(), coins.end());
        int n = coins.size();
        vector<int> dp(amount + 1, -1);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                for (int amt = 0; amt <= amount; amt += coins[0]) {
                    dp[amt] = amt / coins[0];
                }
                continue;
            }
            // dp[i][amt] = min(dp[i][amt - curr] + 1, dp[i - 1][amt]).
            int curr = coins[i];
            for (int amt = 0; amt <= amount; ++amt) {
                if (amt >= curr && dp[amt - curr] >= 0) {
                    if (dp[amt] < 0) dp[amt] = dp[amt - curr] + 1;
                    else {
                        dp[amt] = min(dp[amt], dp[amt - curr] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
};