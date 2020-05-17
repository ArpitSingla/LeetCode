class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        bool **dp=new bool*[n];
        for(int i=0;i<n;i++){
            dp[i]=new bool[n];
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
            count++;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(j==i-1 && s[j]==s[i]){
                    dp[i][j]=1;
                    count++;
                }
                else if(s[i]==s[j] && dp[i-1][j+1]==1){
                    dp[i][j]=1;
                    count++;
                }
            }
        }
        return count;
    }
};