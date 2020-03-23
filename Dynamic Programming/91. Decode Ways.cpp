class Solution {
public:
    int numDecodings(string s) {
        int num=s.length();
        int *dp=new int[num+1];
        for(int i=0;i<=num;i++){
            dp[i]=0;
        }
        return solve(s,dp);
    }
    int solve(string s,int *dp){
        int n=s.length();
        if(s[0]=='0'){
            return 0;
        }
        if(n==0||n==1){
            return 1;
        }
        int count=0;
        if(dp[n]!=0){
            return dp[n];
        }
        if(s[n-1]=='0'){
            if((s[n-2]-48)*10+(s[n-1]-48)!=0 &&((s[n-2]-48)*10+(s[n-1]-48)<=26))
                dp[n]=numDecodings(s.substr(0,n-2));
            else
                dp[n]=0;
        }
        else if((s[n-2]-48)*10+(s[n-1]-48)<=26 && s[n-2]!='0'){
            dp[n]=numDecodings(s.substr(0,n-1))+numDecodings(s.substr(0,n-2));
        }
        else{
            dp[n]=numDecodings(s.substr(0,n-1));
        }
        return dp[n];
    }
};