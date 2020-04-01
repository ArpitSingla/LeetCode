class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return nums[0];
        }
        map<int,int>::iterator it;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        int ans=0;
        for(it=m.begin();it!=m.end();it++){
            if(it->second==1){
                ans=it->first;
            }
        }
        return ans;
    }
};