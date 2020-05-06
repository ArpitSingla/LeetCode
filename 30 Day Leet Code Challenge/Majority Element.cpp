class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        for(auto it:m){
            if(it.second>floor(nums.size()/2)){
                return it.first;
            }
        }
        return 0;
    }
};