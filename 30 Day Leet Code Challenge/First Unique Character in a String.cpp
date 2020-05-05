class Solution {
public:
    int firstUniqChar(string s) {
        map<char,pair<int,int>> m;
        for(int i=0;i<s.size();i++){
            m[s[i]].first++;
            m[s[i]].second=i;
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]].first==1){
                return m[s[i]].second;
            }
        }
        return -1;
    }
};