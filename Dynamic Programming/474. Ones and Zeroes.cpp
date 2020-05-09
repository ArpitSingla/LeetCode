class Solution {
public:
    int dp[601][101][101];
    int solve(vector<string>& strs,int num,int m,int n){
        if((m==0 && n==0) || num==0){
            return 0;
        }
        if(dp[num][m][n]!=0){
            return dp[num][m][n];
        }
        map<char,int> mp;
        for(int i=0;i<strs[num-1].size();i++){
            mp[strs[num-1][i]]=mp[strs[num-1][i]]+1;
        }
        int one=mp['1'];
        int zero=mp['0'];
        if(m>=zero && n>=one){
            dp[num][m][n]=max(solve(strs,num-1,m,n),1+solve(strs,num-1,m-zero,n-one));
            return dp[num][m][n];
        }
        dp[num][m][n]=solve(strs,num-1,m,n);
        return dp[num][m][n];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num=strs.size();
        return solve(strs,num,m,n);
    }
};  