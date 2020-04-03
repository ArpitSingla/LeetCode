class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        int curr_sum=0;
        int best_sum=0;
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(max<nums[i]){
                max=nums[i];
            }
            curr_sum+=nums[i];
            if(curr_sum<0){
                curr_sum=0;
            }
            if(best_sum<curr_sum){
                best_sum=curr_sum;
            }
        }
        if(curr_sum==0 && best_sum==0){
            best_sum=max;
        }
        return best_sum;
    }
};