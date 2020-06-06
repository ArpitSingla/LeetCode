class Solution {
public:
    vector<int> b;
    int sum;
    Solution(vector<int>& w) {
        sum=0;
        for(auto i:w){
            sum+=i;
            b.push_back(sum);
        }
    }
    
    int pickIndex() {
        int temp=rand()%sum;
        int ans=lower_bound(b.begin(),b.end(),temp+1)-b.begin();
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */