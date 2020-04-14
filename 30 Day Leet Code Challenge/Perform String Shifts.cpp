class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n=shift.size();
        int zero=0,one=0;
        for(int i=0;i<n;i++){
            if(shift[i][0]==0){
                zero+=shift[i][1];
            }
            else{
                one+=shift[i][1];
            }
        }
        if(one==zero){
            return s;
        }
        else if(one>zero){
            int temp=one-zero;
            for(int i=0;i<temp;i++){
                s.insert(s.begin(),s[s.size()-1]);
                s.pop_back();
            }
        }
        else{
            int temp=zero-one;
            for(int i=0;i<temp;i++){
                s.push_back(s[0]);
                s.erase(s.begin());
            }
        }
        return s;
    }
};