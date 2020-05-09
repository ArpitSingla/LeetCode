class Solution {
public:
    int minSteps(int n) {
        if(n==1){
            return 0;
        }
        if(n==2){
            return 2;
        }
        if(n==3){
            return 3;
        }
        vector<int> dp(n+1,0);
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<n+1;i++){
            dp[i]=i;
        }
        for(int i=4;i<n+1;i++){
            int curr=i/2;
            for(int j=2;j<=curr;j++){
                if(i%j==0){
                    dp[i]=min(dp[i],(dp[j]+i/j));
                }
            }
        }
        return dp[n];
    }
};