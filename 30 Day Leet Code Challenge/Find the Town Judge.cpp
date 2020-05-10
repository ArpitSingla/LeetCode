class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int n=trust.size();
        if(n==0){
            return 1;
        }
        map<int,int> first;
        map<int,int> second;
        for(int i=0;i<n;i++){
            first[trust[i][0]]++;
            second[trust[i][1]]++;
        }
        for(auto m:second){
            if(first.find(m.first)!=first.end()){
                continue;
            }
            if(m.second==N-1){
                return m.first;
            }
        }
        return -1;
    }
};