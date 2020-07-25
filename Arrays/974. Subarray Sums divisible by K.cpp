class Solution {
public:
    int subarraysDivByK(vector<int>& A, int k) {
        int n=A.size();
        if(n==0){
            return 0;
        }
        unordered_map<int,int> m;
        int sum=0;
        int ans=0;
        m[sum%k]++;
        for(int i=0;i<n;i++){
            sum+=A[i];
            int temp=sum%k;
            if(temp<0){
                temp+=k;               // important condition used to handle remainder of negative numbers
            }
            if(m.count(temp)){
                ans+=m[temp];
            }
            m[temp]++;
        }
        return ans;
    }
};