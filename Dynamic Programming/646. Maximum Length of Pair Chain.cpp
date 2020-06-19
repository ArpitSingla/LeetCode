class Solution {
public:
    static bool comp(const vector<int> &a,const vector<int> &b){
        if(a[0]+a[1]==b[0]+b[1]){
            return a[0]<b[0];
        }    
        return a[0]+a[1]<b[0]+b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end(),comp);
        for(int i=0;i<n;i++){
            cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
        }
        vector<int> dp(n,1);
        int count=0;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }    
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};