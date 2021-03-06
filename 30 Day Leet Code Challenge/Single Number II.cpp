class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(auto n:nums){
                if(n&(1<<i)){
                    sum++;
                }
            }
            if(sum%3){
                ans+=1<<i;  
            }
        }
        return ans;
    }
};