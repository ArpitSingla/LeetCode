class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n=points.size();
        multimap<double,int> arr;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            double dist=sqrt((double)pow(points[i][0],2)+pow(points[i][1],2));
            arr.insert({dist,i});
        }
        int count=0;
        for(auto i:arr){
            if(count==K){
                return ans;
            }
            count++;
            ans.push_back({points[i.second][0],points[i.second][1]});
        }
        return ans;
    }
};