class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        int *dp1=new int[n];
        int *dp2=new int[n];
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);
        dp2[0]=nums[1];
        dp2[1]=max(nums[2],nums[1]);
        for(int i=2;i<n-1;i++){
            dp1[i]=max(dp1[i-2]+nums[i],dp1[i-1]);
            dp2[i]=max(dp2[i-2]+nums[i+1],dp2[i-1]);
        }
        int ans=max(dp1[n-2],dp2[n-2]);
        return ans;
    }
};