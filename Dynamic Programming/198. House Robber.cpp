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
        int *output=new int[n];
        output[0]=nums[0];
        output[1]=max(output[0],nums[1]);
        for(int i=2;i<n;i++){
            output[i]=max(output[i-1],output[i-2]+nums[i]);
        }
        return output[n-1];
    }
};