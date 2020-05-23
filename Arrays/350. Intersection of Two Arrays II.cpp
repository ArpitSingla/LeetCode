class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> ans;
        for(auto i1:nums1){
            m1[i1]++;
        }
        for(auto i2:nums2){
            m2[i2]++;
        }
        if(n<=m){
            for(int i=0;i<n;i++){
                if((m2.find(nums1[i])!=m2.end())&& m2[nums1[i]]){
                    ans.push_back(nums1[i]);
                    m2[nums1[i]]--;
                }
            }    
        }
        else{
            for(int i=0;i<m;i++){
                if((m1.find(nums2[i])!=m1.end())&& m1[nums2[i]]){
                    ans.push_back(nums2[i]);
                    m1[nums2[i]]--;
                }
            }
        }
        return ans;
    }
};