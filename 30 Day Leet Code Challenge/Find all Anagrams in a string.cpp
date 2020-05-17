class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> sv(26,0),pv(26,0),ans;
        int n=s.size();
        int k=p.size();
        if(n<k){
            return ans;
        }
        for(int i=0;i<k;i++){
            sv[s[i]-'a']++;
            pv[p[i]-'a']++;
        }
        if(pv==sv){
            ans.push_back(0);
        }
        for(int i=k;i<n;i++){
            sv[s[i]-'a']++;
            sv[s[i-k]-'a']--;
            if(pv==sv){
                ans.push_back(i-k+1);
            }
        }
        return ans;
    }
};