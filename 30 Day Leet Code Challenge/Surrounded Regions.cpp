class Solution {
public:
    void rec(vector<vector<char>>& board,int i,int j,int n,int m){
        if(i>=0 && i<n && j>=0 && j<m && board[i][j]=='O'){
            board[i][j]='1';
            rec(board,i-1,j,n,m);
            rec(board,i+1,j,n,m);
            rec(board,i,j-1,n,m);
            rec(board,i,j+1,n,m);
        }        
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        if(n<=2){
            return;
        }
        int m=board[0].size();
        if(m<=2){
            return;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'&&(i==0 || j==0 || i==n-1 || j==m-1)){
                    rec(board,i,j,n,m);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='1'){
                    board[i][j]='O';
                }
            }
        }
    }
};