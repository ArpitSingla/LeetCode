class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n=S.size();
        int m=J.size();
        map<char,int> stone;
        for(int i=0;i<n;i++){
            stone[S[i]]++;
        }
        int ans=0;
        for(int i=0;i<m;i++){
            ans+=stone[J[i]];
        }
        return ans;
    }
};