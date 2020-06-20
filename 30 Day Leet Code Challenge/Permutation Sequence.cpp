class Solution {
public:
    string getPermutation(int n, int k) {
        string ans;
        string nums="123456789";
        vector<int> fact(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i]=fact[i-1]*i;
        }
        k--;
        for(int i=n;i>=1;i--){
            int temp=k/fact[i-1];
            k=k%fact[i-1];
            ans.push_back(nums[temp]);
            nums.erase(nums.begin()+temp);
        }
        return ans;
    }
};