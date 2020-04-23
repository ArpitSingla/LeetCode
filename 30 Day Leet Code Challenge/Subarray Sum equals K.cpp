class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int total=0;
        int ans=0;
        map<int,int> m;
        m[0]=1;
        for(int i=0;i<n;i++){
            total+=nums[i];
            if(m.count(total-k)){
                ans+=m[total-k];
            }
            m[total]++;   
        }
        return ans;
    }
};

