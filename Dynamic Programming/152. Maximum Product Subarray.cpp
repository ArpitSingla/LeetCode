class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==1 && nums[n-1]<0){
            return nums[n-1];
        }
        int curr_max=1,curr_min=1;
        int best_prod=1;
        int flag=0;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                curr_max=curr_max*nums[i];
                curr_min=min(curr_min*nums[i],1);
                flag=1;
            }
            else if(nums[i]==0){
                curr_max=1;
                curr_min=1;
            }
            else{
            
                int temp=curr_max;
                curr_max=max(curr_min*nums[i],1);
                curr_min=temp*nums[i];
            }
            if(best_prod<curr_max){
                best_prod=curr_max;
            }
        }
        if(curr_max==1 && flag==0){
            return 0;
        }
        return best_prod;
    }
//     int maxProduct(vector<int>& nums) {
// 		int MAX=nums[0], MIN=nums[0],res=nums[0];
// 		for(int i=1;i<nums.size();i++){
// 			int temp1=MAX, temp2=MIN;
// 			MAX=max(temp2*nums[i],max(temp1*nums[i],nums[i]));
// 			MIN=min(temp2*nums[i],min(temp1*nums[i],nums[i]));
// 			res=max(res,MAX);
// 		}

// 		return res;
// 	}
};
        