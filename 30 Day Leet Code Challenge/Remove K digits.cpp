#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> s;
        for(char c:num){
            while(!s.empty() && k>0 && s.top()>c){
                s.pop();
                k--;
            }
            if(!s.empty()||c!='0'){
                s.push(c);
            }
        }
        while(!s.empty()&&k--){
            s.pop();
        }
        if(s.empty()){
            return "0";
        }
        while(!s.empty()){
            num[n-1]=s.top();
            s.pop();
            n--;
        }
        return num.substr(n);
    }
};

#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size()){
            return "0";
        }
        int n=num.size();
        int i=0;
        while(k!=0){
            i=(i>0)?(i-1):0;
            while(i<n && num[i]<=num[i+1]){
                i++;
            }
            num.erase(num.begin()+i);
            k--;
        }
        auto count=num.find_first_not_of("0");
        num.erase(0,count);
        if(num.size()==0){
            return "0";
        }
        return num;
    }
};