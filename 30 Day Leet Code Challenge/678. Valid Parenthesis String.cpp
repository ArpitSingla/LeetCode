class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int> > s1,s2;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                s1.push(make_pair('(',i));
            }
            else if(s[i]==')'){
                if(!s1.empty()){
                    s1.pop();
                }
                else if(!s2.empty()&&s2.top().second<i){
                    s2.pop();
                }
                else{
                    return false;
                }
            }
            else{
                s2.push(make_pair('*',i));
            }
        }
        while(s1.size() && s2.size()){
            if(s1.top().second<s2.top().second){
                s1.pop();
                s2.pop();
            }
            else{
                return false;
            }
        }
        if(s1.empty()){
            return true;
        }
        return false;
    }
};
  