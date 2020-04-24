class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		if(m==n){
			return m;
		}
		if(m == 0){
			return 0;
		}
		int ans = 0;
		int diff = n-m+1;
		for(unsigned int bit = 1, set = 2; set<=n; bit++, set*=2){
			if(diff > set){
				continue;
			}
			int mask = (1<<bit);
			if((m&mask) && (n&mask)){
				ans^=mask;
			}
		}
        return ans;
    }
};