class Solution {
public:
    static bool comp(pair<char,int> &a,pair<char,int> &b){
        if(a.second==b.second){
            return a.first<=b.first;
        }
        else{
            return a.second>b.second;    
        }
    }
    string frequencySort(string s) {
        map<char,int> m;
        string ans;
        for(auto ch:s){
            m[ch]++;
        }
        vector<pair<char,int>> v;
        for(auto ch:m){
            v.push_back(make_pair(ch.first,ch.second));
        }
        sort(v.begin(),v.end(),comp);
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].second;j++){
                ans+=v[i].first;
            }   
        }
        return ans;
    }
};