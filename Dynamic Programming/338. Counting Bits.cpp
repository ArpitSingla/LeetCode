class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        int *dp=new int[num+1];
        ans.push_back(0);
        if(num==0){
            return ans;
        }
        int count=0;
        int count1=count-1;
        dp[0]=0;
        for(int i=1;i<=num;i++){
            int temp=pow(2,count);
            if(i==temp){
                count++;
                count1++;
                dp[i]=1;
            }
            else{
                int var=pow(2,count1);
                dp[i]=dp[i-var]+1;
            }
            ans.push_back(dp[i]);
        }
        return ans;
    }
};