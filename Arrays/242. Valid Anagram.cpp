class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> sv(26,0);
        int n=s.size();
        int m=t.size();
        if(n!=m){
            return false;
        }
        for(int i=0;i<n;i++){
            sv[s[i]-'a']++;
            sv[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(sv[i]!=0){
                return false;
            }
        }
        return true;
    }
};