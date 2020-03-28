class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int *dp=new int[n];
        dp[0]=1;
        for(int i=1;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]>=nums[i]){
                    continue;
                }
                int ans=dp[j]+1;
                if(ans>dp[i]){
                    dp[i]=ans;
                }
            }
        }
        int best=*max_element(dp,dp+n);
        return best;
    }
};