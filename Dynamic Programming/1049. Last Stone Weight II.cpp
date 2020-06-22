class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        if(n==0){
            return 0;
        }
        int sumo=accumulate(stones.begin(),stones.end(),0);
        int sum=sumo/2;
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j>=stones[i-1]){
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-stones[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        int temp;
        for(int i=sum;i>0;i--){
            if(dp[n][i]==true){
                temp=i;
                break;
            }
        }
        return sumo-2*temp;
    }
};