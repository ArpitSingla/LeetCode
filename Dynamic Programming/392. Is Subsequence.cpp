class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        int p=0,q=0;
        for(;p<n && q<m;){
            if(s[p]==t[q]){
                p++;
                q++;
            }
            else{
                q++;    
            }
        }
        if(p==n){
            return true;
        }
        return false;
    }
};