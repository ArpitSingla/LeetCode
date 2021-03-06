class Solution {
public:
    long long int mySqrt(int x) {
        long long int low=1;
        long long int high=x;
        while(low<=high){
            long long int mid=low+(high-low)/2;
            if(mid*mid==x || (mid*mid<x && (mid+1)*(mid+1)>x)){
                return mid;
            }
            else if(mid*mid>x){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return x;
    }
};