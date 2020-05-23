class Solution {
public:
    int countPrimes(int n) {
        bool *ans=new bool[n];
        for(int i=0;i<n;i++){
            ans[i]=true;
        }
        for(int i=2;i*i<n;i++){
            if(ans[i]){
                for(int j=i*i;j<n;j+=i){
                    ans[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(ans[i]){
                count++;
            }
        }
        return count;
    }
};