class Solution {
public:
    int rec(vector<vector<int>>& grid,int i,int j){
        if(grid[i][j]==0){
            return 0;
        }
        int ans=0;
        int temp=grid[i][j];
        grid[i][j]=0;
        if(i>0){
            ans=max(ans,temp+rec(grid,i-1,j));
        }
        if(j>0){
            ans=max(ans,temp+rec(grid,i,j-1));
        }
        if(i<grid.size()-1){
            ans=max(ans,temp+rec(grid,i+1,j));
        }
        if(j<grid[0].size()-1){
            ans=max(ans,temp+rec(grid,i,j+1));
        }
        grid[i][j]=temp;
        return ans;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,rec(grid,i,j));
            }
        }
        return ans;
    }
};