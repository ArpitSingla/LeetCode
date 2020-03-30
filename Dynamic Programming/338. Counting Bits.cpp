class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        ans[0]=0;
        if(num==0){
            return ans;
        }
        int count=0;
        int count1=count-1;
        for(int i=1;i<=num;i++){
            int temp=pow(2,count);
            if(i==temp){
                count++;
                count1++;
                ans[i]=1;
            }
            else{
                int var=pow(2,count1);
                ans[i]=ans[i-var]+1;
            }
        }
        return ans;
    }
};
