class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return;
        }
        vector<int> index;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                index.push_back(i);
            }
        }
        int count=0;
        for(int i=0;i<index.size();i++){
            nums.erase(nums.begin()+index[i]-count);
            count++;
        }
        for(int i=0;i<index.size();i++){
            nums.push_back(0);
        }
    }
};