class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        if(m==0){
            return 0;
        }
        int **output=new int*[m];
        for(int i=0;i<m;i++){
            int temp=triangle[i].size();
            output[i]=new int[temp];
        }
        output[0][0]=triangle[0][0];
        for(int i=1;i<m;i++){
            int temp=triangle[i].size();
            for(int j=0;j<temp;j++){
                if(j==0){
                    output[i][j]=output[i-1][j]+triangle[i][j];    
                }
                else if(j==temp-1){
                    output[i][j]=output[i-1][j-1]+triangle[i][j];
                }
                else{
                    output[i][j]=min(output[i-1][j-1],output[i-1][j])+triangle[i][j];
                }
            }    
        }
        int ans=*min_element(output[m-1],output[m-1]+triangle[m-1].size());
        return ans;
    }
};