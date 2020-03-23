class Solution {
public:
    // int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    //     int m=obstacleGrid[0].size();
    //     int n=obstacleGrid.size();
    //     if(m==0 && n==0){
    //         return 0;
    //     }
    //     int **output=new int*[n+1];
    //     for(int i=0;i<=n;i++){
    //         output[i]=new int[m+1];
    //         for(int j=0;j<=m;j++){
    //             output[i][j]=0;
    //         }
    //     }
    //     output[0][1]=1;
    //     for(int i=1;i<=n;i++){
    //         for(int j=1;j<=m;j++){
    //             if(obstacleGrid[i-1][j-1]==1){
    //                 output[i][j]=0;
    //             }
    //             else{
    //                 output[i][j]=output[i-1][j]+output[i][j-1];    
    //             }
    //         }
    //     }
    //     return output[n][m];
    int path(int x,int y, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        if(x>=row || y>=col || obstacleGrid[x][y] == 1)return 0;
        
        if(x == row - 1 && y == col - 1) {
            return 1;
        }
        if(dp[x][y] != -1)return dp[x][y];
        dp[x][y] = path(x+1, y, obstacleGrid,dp) + path(x, y+1, obstacleGrid,dp);
        return dp[x][y];
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int> > dp( obstacleGrid.size() , vector<int> (obstacleGrid[0].size(), -1));
        return path(0,0,obstacleGrid,dp);
    }
};