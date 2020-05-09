class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        if(n==0){
            return 0;
        }
        int sum=accumulate(stones.begin(),stones.end(),0);
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i][j]||dp[i-1][j-stones[i-1]];
                }
            }
        }
        cout<<sum<<endl;
        int ans=0;
        for(int i=sum/2;i>=0;i--){
            if(dp[n][i]==1){
                ans=sum-2*i;
                cout<<i<<endl;
                break;
            }
        }
        return ans;
    }
};