class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size();
        int curr_max=0;
        int curr_min=0;
        int max_sum=INT_MIN;
        int min_sum=INT_MAX;
        for(int i=0;i<n;i++){
            curr_max=max(curr_max+A[i],A[i]);
            curr_min=min(curr_min+A[i],A[i]);
            max_sum=max(max_sum,curr_max);
            min_sum=min(min_sum,curr_min);
        }
        int sum=accumulate(A.begin(),A.end(),0);
        return max_sum>0 ? max(max_sum,sum-min_sum):max_sum;
    }
};