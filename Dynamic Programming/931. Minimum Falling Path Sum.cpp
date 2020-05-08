class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size();
        int m=A[0].size();
        if(m==0||n==0){
            return 0;
        }
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[0][i]=A[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(j==0){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==m-1){
                    dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]);    
                }
                else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
                }
                dp[i][j]+=A[i][j];
            }
        }
        int ans=*min_element(dp[n-1].begin(),dp[n-1].end());
        return ans;
    }
};