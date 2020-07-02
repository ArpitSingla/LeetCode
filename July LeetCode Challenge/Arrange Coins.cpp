class Solution {
public:
    int arrangeCoins(int n) {
        long long int left=0;
        long long int right=n;
        while(left<=right){
            long long int mid=left+(right-left)/2;
            long long int curr=mid*(mid+1)/2;
            if(n==curr){
                return mid;
            }
            else if(n>curr){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return right;
    }
};