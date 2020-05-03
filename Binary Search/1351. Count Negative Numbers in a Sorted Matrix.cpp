class Solution {
public:
    int binarySearch(vector<int> &arr,int m){
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]<0){
                if(arr[mid-1]>=0){
                    return m-mid;    
                }
                else{
                    high=mid-1;
                }
            }
            else if(arr[mid]>=0){
                low=mid+1;
            }
        }
        return 0;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for(int i=0;i<n;i++){
            if(grid[i][0]<0){
                count+=m;
            }
            else{
                count=count+binarySearch(grid[i],m);  
            }
        }
        return count;
    }
};