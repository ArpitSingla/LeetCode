class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> m;
        m[0]=-1;
        int i=0,maxlen=0,sum=0;
        while(i<nums.size())
        {
            if(nums[i]==0)
                sum--;
            else
                sum++;
            if(m.count(sum)==0)
                m[sum]=i;
            else
                maxlen=max(maxlen,i-m[sum]);
            i++;
        }
        return maxlen;
    }
};