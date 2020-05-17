class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool **dp=new bool*[n];
        for(int i=0;i<n;i++){
            dp[i]=new bool[n];
            for(int j=0;j<n;j++){
                dp[i][j]=0;
            }
        }
        int best=INT_MIN;
        int curr=0;
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        curr=1;
        best=1;
        string str=s.substr(0,curr);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(s[i]==s[j] && i-1==j){
                    dp[i][j]=1;
                    curr=i-j+1;
                }
                else if(s[i]==s[j] && dp[i-1][j+1]){
                    dp[i][j]=1;
                    curr=i-j+1;
                }
                if(best<curr){
                    cout<<i<<" "<<j<<endl;
                    cout<<curr<<endl;
                    best=curr;
                    str=s.substr(j,curr);
                }
            }
        }
        return str;
    }
};