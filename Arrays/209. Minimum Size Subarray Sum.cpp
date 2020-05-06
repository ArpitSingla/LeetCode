class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int front=0,back=0;
        int ans=INT_MAX;
        int window_sum=nums[0];
        while(true){
            if(window_sum==s){
                ans=min(ans,back-front+1);
                if(back+1==nums.size()){
                    break;
                }
                window_sum+=nums[++back];
                window_sum-=nums[front++];
            }
            else if(window_sum<s){
                if(back+1==nums.size()){
                    break;
                }
                window_sum+=nums[++back];
            }
            else{
                ans=min(ans,1+back-front);
                window_sum-=nums[front++];
            }
        }
        if(ans!=INT_MAX){
            return ans;
        }
        return 0;
    }
};