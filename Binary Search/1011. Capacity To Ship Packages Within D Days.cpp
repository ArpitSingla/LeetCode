class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int low=INT_MIN;
        int high=0;
        for(int w:weights){
            low=max(low,w);
            high+=w;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            int curr_weight=0;
            int days=1;
            for(int w:weights){
                if(curr_weight+w>mid){
                    days++;
                    curr_weight=0;
                }
                curr_weight+=w;
            }
            if(days>D){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};