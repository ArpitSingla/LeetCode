class Solution {
public:
    
    void solve(vector<vector<char>>& grid,int si,int sj,int ei,int ej,vector<vector<bool>>& ans){
        if(si>=ei||sj>=ej||si<0||sj<0||grid[si][sj]=='0'||ans[si][sj]==false){
            return;
        }
        ans[si][sj]=false;
        solve(grid,si+1,sj,ei,ej,ans);
        solve(grid,si-1,sj,ei,ej,ans);
        solve(grid,si,sj+1,ei,ej,ans);
        solve(grid,si,sj-1,ei,ej,ans);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0){
            return 0;
        }
        int m=grid[0].size();
        if(m==0){
            return 0;
        }
        int count=0;
        vector<vector<bool>> ans(n,vector<bool>(m,true));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&& ans[i][j]==true){
                    count++;
                    solve(grid,i,j,n,m,ans);
                }
            }
        }
        return count;
    }
};