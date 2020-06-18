class Solution {
public:
    int hIndex(vector<int>& citations) {
        int l=0;
        int n=citations.size();
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(citations[mid]==n-mid){
                return citations[mid];
            }
            else if(citations[mid]>n-mid){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return n-l;
    }
};