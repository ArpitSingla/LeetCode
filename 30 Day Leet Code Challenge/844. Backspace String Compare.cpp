class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        stack<char> t;
        for(char i:S){
            if(i=='#' && s.empty()){
                continue;
            }
            else if(i=='#'){
                s.pop();
            }
            else{
                s.push(i);
            }
        }
        for(char j:T){
            if(j=='#'&& t.empty()){
                continue;
            }
            else if(j=='#'){
                t.pop();
            }
            else{
                t.push(j);               
            }
        }
        while(!s.empty()&&!t.empty()){
            if(s.top()==t.top()){
                s.pop();
                t.pop();
            }
            else{
                return false;
            }
        }
        if(s.empty()&&t.empty()){
            return true;    
        }
        return false;
    }
};