class Solution {
public:
    void solve(vector<int> &count,int &result){
        for(int i=0;i<26;i++){
            if(count[i]){
                count[i]--;
                result++;
                solve(count,result);
                count[i]++;
            }
        }
    }
    int numTilePossibilities(string tiles) {
        vector<int> count(26,0);
        for(auto c:tiles){
            count[c-'A']++;
        }
        int result=0;
        solve(count,result);
        return result;
    }
};
