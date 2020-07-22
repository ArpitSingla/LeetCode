class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=profit.size();
        vector<vector<int>> val(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            val[i][0]=startTime[i];
            val[i][1]=endTime[i];
            val[i][2]=profit[i];
        }
        sort(val.begin(),val.end(),comp);
        sort(endTime.begin(),endTime.end());
        vector<int> dp(n,INT_MIN);
        dp[0]=val[0][2];
        for(int i=1;i<n;i++){
            int cost=val[i][2];
            int index=upper_bound(endTime.begin(),endTime.end(),val[i][0])-endTime.begin()-1;
            if(index!=-1){
                cost+=dp[index];
            }
            dp[i]=max(dp[i-1],cost);
        }
        return dp[n-1];
    }
};