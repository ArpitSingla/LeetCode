class Solution {
public:
    // Using Fast and Slow Pointer
    int findDuplicate(vector<int>& nums) {
        int fast=nums[0];
        int slow=nums[0];
        do{
            fast=nums[nums[fast]];
            slow=nums[slow];
        }while(fast!=slow);
        slow=nums[0];
        while(fast!=slow){
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }

    //Using Binary Search
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=1,right=n;
        while(left<=right){
            int m=left+(right-left)/2;
            int temp=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=m){
                    temp++;
                }
            }
            if(temp>m){
                right=m-1;
            }
            else{
                left=m+1;
            }
        }
        return left;
    }
};