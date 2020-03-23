class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        if(n==2){
            return min(cost[0],cost[1]);
        }
        int *arr=new int[n+1];
        arr[0]=cost[0];
        arr[1]=cost[1];
        for(int i=2;i<n;i++){
            arr[i]=cost[i]+min(arr[i-1],arr[i-2]);
        }
        arr[n]=min(arr[n-1],arr[n-2]);
        return arr[n];
    }
};