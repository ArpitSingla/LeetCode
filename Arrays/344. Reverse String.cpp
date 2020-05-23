class Solution {
public:
    void reverseString(vector<char>& s) {   //using a stack
        stack<char> st;
        for(auto ch:s){
            st.push(ch);
        }
        vector<char> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        for(int i=0;i<ans.size();i++){
            s[i]=ans[i];
        }
    }

    void reverseString(vector<char>& s) {    //using 2 pointers
        int n=s.size(); 
        int left=0,right=n-1;
        while(left<right){
            char temp=s[left];
            s[left++]=s[right];
            s[right--]=temp;
        }
    }
};