//Similar to LIS problem 
//O(n^2)

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n<=1){
            return nums;
        }
        int index=0;
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1),ind(n,-1);
        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[j]%nums[i]==0){
                    if(dp[i]<dp[j]+1){
                        ind[i]=j;
                        dp[i]=dp[j]+1;
                    }
                }
            }
            if(dp[index]<dp[i]){
                index=i;
            }
        }
        vector<int> result;
        while(index>=0){
            result.push_back(nums[index]);
            index=ind[index];
        }
        return result;
    }
}; 