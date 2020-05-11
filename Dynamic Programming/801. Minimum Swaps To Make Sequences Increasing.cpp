class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int *swap=new int[n]{};
        int *noswap=new int[n]{};
        for(int i=0;i<n;i++){
            swap[i]=n;
            noswap[i]=n;
        }
        swap[0]=1;
        noswap[0]=0;
        for(int i=1;i<n;i++){
            if(A[i]>A[i-1] && B[i]>B[i-1]){
                swap[i]=swap[i-1]+1;
                noswap[i]=noswap[i-1];
            }
            if(A[i]>B[i-1] && B[i]>A[i-1]){
                swap[i]=min(noswap[i-1]+1,swap[i]);
                noswap[i]=min(noswap[i],swap[i-1]);
            }
        }
        int ans=min(swap[n-1],noswap[n-1]);
        return ans;
    }
};
