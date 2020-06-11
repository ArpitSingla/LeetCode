class Solution {
public:
    void rec(vector<vector<string>> &res,vector<string> &temp,string &s,int start){
        if(start==s.size()){
            res.push_back(temp);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                temp.push_back(s.substr(start,i-start+1));
                rec(res,temp,s,i+1);
                temp.pop_back();
            }
        }
    }
    bool isPalindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        rec(res,temp,s,0);
        return res;
    }
};