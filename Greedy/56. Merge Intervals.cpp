class Solution {
public:
    static bool compare(vector<int> &a,vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        if(n==0){
            return ans;
        }
        sort(intervals.begin(),intervals.end(),compare);
        int start=intervals[0][0];
        int end=intervals[0][1];
        ans.push_back({start,end});
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
                ans.pop_back();
                ans.push_back({start,end});
            }
            else{
                start=intervals[i][0];
                end=intervals[i][1];
                ans.push_back({start,end});
            }
        }
        return ans;
    }
};