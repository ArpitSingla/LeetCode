class Solution {
public:
    vector<vector<int>> solve(vector<vector<int>>& image,int n,int m,int sr, int sc, int newColor,int color){
        if(sr<0||sc<0||sr>=n||sc>=m){
            return image;
        }
        if(image[sr][sc]!=color){
            return image;
        }
        if(image[sr][sc]==newColor){
            return image;
        }
        image[sr][sc]=newColor;
        solve(image,n,m,sr+1,sc,newColor,color);
        solve(image,n,m,sr-1,sc,newColor,color);
        solve(image,n,m,sr,sc+1,newColor,color);
        solve(image,n,m,sr,sc-1,newColor,color);
        return image;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n=image.size();
        int m=image[0].size();
        int color=image[sr][sc];
        return solve(image,n,m,sr,sc,newColor,color);
    }
};