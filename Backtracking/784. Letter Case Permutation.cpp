class Solution {
public:
    void solve(string s,vector<string> &ans,int start){   //Normal Naive Solution
        ans.push_back(s);
        for(int i=start;i<s.length();i++){
            if(isalpha(s[i])){
                if(isupper(s[i])){
                    s[i]+=32;
                    if(count(ans.begin(),ans.end(),s)==0)
                        solve(s,ans,start+1);
                    s[i]-=32;
                }
                else{
                    s[i]-=32;
                    if(count(ans.begin(),ans.end(),s)==0)
                        solve(s,ans,start+1);
                    s[i]+=32;
                }
            }
        }
        return;
    }
    
    void solve(string s,vector<string> &ans,int j){      // Case Toggling
        ans.push_back(s);
        if(j>=s.size()){
            return;
        }
        for(int i=j;i<s.size();i++){
            if(isalpha(s[i])){
                s[i]^=(1<<5);
                solve(s,ans,i+1);
                s[i]^=(1<<5);
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        vector<string> ans;
        solve(S,ans,0);
        return ans;
    }
};