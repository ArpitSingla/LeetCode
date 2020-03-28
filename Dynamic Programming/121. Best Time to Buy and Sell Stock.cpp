class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0){
            return 0;
        }
        int maxProfit=0;
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--){
            if(prices[i]<maxi){
                maxProfit=max(maxProfit,maxi-prices[i]);
            }
            else{
                maxi=prices[i];
            }
        }
        return maxProfit;
    }
};