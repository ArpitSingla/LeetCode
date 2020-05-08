class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-1;
        int ans;
        while(low<high){
            int mid=low+(high-low)/2;
            if(nums[mid]<nums[mid+1]){
                low=mid+1;
            }
            else{
                ans=mid;
                high=mid;
            }
        }
        return high;
    }
};