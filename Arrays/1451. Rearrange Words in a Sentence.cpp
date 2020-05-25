class Solution {
public:
    static bool comp(const pair<int,int> &a,const pair<int,int> &b){
        if(a.second==b.second){
            return a.first<b.first;
        }
        return a.second<b.second;
    }
    string arrangeWords(string text) {
        string ans;
        int n=text.size();
        vector<pair<int,int>> v;
        vector<pair<string,int>> s;
        int k=0,j=0;
        text[0]+=32;
        while(k<=n){
            if(text[k]==' '||text[k]=='\0'){
                s.push_back({text.substr(j,k-j),j});
                j=k+1;
            }
            k++;
        }
        for(auto i:s){
            v.push_back({i.second,i.first.size()});
        }
        sort(v.begin(),v.end(),comp);
        int count=0;
        for(auto it:v){
            ans+=text.substr(it.first,it.second);
            count++;
            if(count==v.size()){
                break;
            }
            ans+=" ";
        }
        ans[0]-=32;
        return ans;
    }
};