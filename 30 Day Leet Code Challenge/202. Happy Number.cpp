class Solution {
public:
    bool isHappy(int n) {
        if(n==1||n==7){
            return true;
        }
        else if(n>=0 && n<=9){
            return false;
        }
        int ans=0;
        int a;
        while(n!=0){
            a=n%10;
            n=n/10;
            ans=ans+a*a;
        }
        if(ans==1){
            return true;
        }
        return isHappy(ans);
    }
};