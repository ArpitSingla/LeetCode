class Solution {
public:
    
    // int lcs(string text1,int n1,string text2,int n2,int **dp){
    //     if(n1==0 || n2==0){
    //         return 0;
    //     }
    //     if(dp[n1][n2]!=-1){
    //         return dp[n1][n2];
    //     }
    //     if(text1[0]==text2[0]){
    //         dp[n1][n2]=lcs(text1.substr(1),n1-1,text2.substr(1),n2-1,dp)+1;
    //     }
    //     else{
    //         dp[n1][n2]=max(lcs(text1.substr(1),n1-1,text2,n2,dp),lcs(text1,n1,text2.substr(1),n2-1,dp));
    //     }
    //     return dp[n1][n2];
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        int **dp=new int*[n1+1];
        for(int i=0;i<=n1;i++){
            dp[i]=new int[n2+1];
            for(int j=0;j<=n2;j++){
                dp[i][j]=0;
            }
        }
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
        //return lcs(text1,n1,text2,n2,dp);
    }
};