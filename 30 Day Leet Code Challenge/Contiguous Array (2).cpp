class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        m[0]=-1;
        int sum=0;
        int maxl=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                sum++;
            }
            if(nums[i]==0){
                sum--;
            }
            if(m.count(sum)==0){
                m[sum]=i;
            }
            else{
                maxl=max(maxl,i-m[sum]);
            }
        }
        return maxl;
    }
};