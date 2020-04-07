class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
            vector<vector<string>> ans;
            map<string,vector<string>> m;
            for(int i=0;i<n;i++){
                string temp=strs[i];
                sort(temp.begin(),temp.end()); //solved using sorting each string
                m[temp].push_back(strs[i]);
            }
            for(auto it=m.begin();it!=m.end();it++){
                ans.push_back(it->second);
            }
            return ans;
        // int n=strs.size();
        // vector<vector<string>> ans;
        // if(n==0){
        //     return ans;
        // }
        // map<int,vector<string>> m;
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=0;j<strs[i].size();j++){
        //         sum=sum+strs[i][j];   // solved using sum of ASCII values
        //     }
        //     m[sum].push_back(strs[i]);    
        // }
        // for(auto it=m.begin();it!=m.end();it++){
        //     ans.push_back(it->second);
        // }
        // return ans;
    }
};