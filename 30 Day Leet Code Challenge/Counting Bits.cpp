class Solution {
public:
    vector<int> countBits(int num) {    //DP Solution
        vector<int> ans;
        int *dp=new int[num+1];
        dp[0]=0;
        ans.push_back(0);
        int count=1;
        for(int i=1;i<=num;i++){
            int temp=pow(2,count);
            if(i==temp){
                dp[i]=1;
                count++;
            }
            else{
                int var=pow(2,count-1);
                dp[i]=dp[i-var]+1;
            }
            ans.push_back(dp[i]);
        }
        return ans;
    }

    vector<int> countBits(int num) {  //Bit Manipulation fast solution
        vector<int> ans(num+1,0);
        for(int i=1;i<=num;i++){
            ans[i]=ans[i&(i-1)]+1;
        }
        return ans;
    }
};