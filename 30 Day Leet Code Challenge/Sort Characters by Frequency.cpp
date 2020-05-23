//why we use static for custom comparators//
//https://leetcode.com/discuss/general-discussion/547798/Static-Comparator-function-for-sort-(Reasons-as-to-why)//

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

//O(n) bucket sort with way to extra space 

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;

        //count frequency of each character
        for(char c:s) freq[c]++;
        //put character into frequency bucket
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        //form descending sorted string
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty())
                res.append(bucket[i]);
        }
        return res;
    }
}; 