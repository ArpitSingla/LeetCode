class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        int temp=0;
        for(auto n:nums){
            temp^=n;
        }
        int bit;
        for(int i=0;i<32;i++){
            if(temp&(1<<i)){
                bit=i;
                break;
            }
        }
        int var1=0,var2=0;
        for(auto n:nums){
            if(n&(1<<bit)){
                var1^=n;
            }
            else{
                var2^=n;
            }
        }
        ans.push_back(var1);
        ans.push_back(var2);
        return ans;
    }
};