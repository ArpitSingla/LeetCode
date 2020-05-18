class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s2.size();
        int k=s1.size();
        if(k>n){
            return false;
        }
        vector<int> tv(26,0),pv(26,0);
        for(int i=0;i<k;i++){
            tv[s2[i]-'a']++;
            pv[s1[i]-'a']++;
        }
        if(pv==tv){
            return true;
        }
        for(int i=k;i<n;i++){
            tv[s2[i]-'a']++;
            tv[s2[i-k]-'a']--;
            if(pv==tv){
                return true;
            }
        }
        return false;
    }
};