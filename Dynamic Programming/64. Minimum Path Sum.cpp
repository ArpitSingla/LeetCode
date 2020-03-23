class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==0 || n==0){
            return 0;
        }
        int **output=new int*[m+1];
        for(int i=0;i<=m;i++){
            output[i]=new int[n+1];
            for(int j=0;j<=n;j++){
                output[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            output[1][i]=output[1][i-1]+grid[0][i-1];
        }
        for(int i=1;i<=m;i++){
            output[i][1]=output[i-1][1]+grid[i-1][0];
        }
        for(int i=2;i<=m;i++){
            for(int j=2;j<=n;j++){
                output[i][j]=min(output[i-1][j],output[i][j-1])+grid[i-1][j-1];
            }
        }
        return output[m][n];
    }
};