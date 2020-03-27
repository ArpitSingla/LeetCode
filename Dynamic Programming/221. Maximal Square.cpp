class Solution {
public:
	int maximalSquare(vector<vector<char>>& matrix) {
		if(matrix.size()==0) return 0;
		int m=matrix.size();
		int n=matrix[0].size();
		vector<vector<int>> dp(m,vector<int>(n));
		int ans=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=matrix[i][j]-'0';
				if(dp[i][j]==0) continue;
				if(i==0 || j==0){}
				else{
					dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
				}

				ans=max(ans,dp[i][j]*dp[i][j]);
			}
		}
		return ans;
	}
};
