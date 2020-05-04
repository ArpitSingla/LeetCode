class Solution {
public:
    int findComplement(int num) {
        if(num==0){
            return 1;
        }
        int n=log2(num)+1;
        int ans=(unsigned)(1<<n)-1;
        ans=num^ans;
        return ans;
    }
};