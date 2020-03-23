class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int current_sum=0;
        int best_sum=0;
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(max<nums[i]){
                max=nums[i];
            }
            current_sum=current_sum+nums[i];
            if(best_sum<current_sum){
                best_sum=current_sum;
            }
            if(current_sum<0){
                current_sum=0;
            }
        }
        if(current_sum==0 && best_sum==0){
            best_sum=max;
        }
        return best_sum;
    }
};