class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n<=2){
            return true;
        }
        float slope=(float)(coordinates[1][1]-coordinates[0][1])/(coordinates[1][0]-coordinates[0][0]);
        for(int i=1;i<n-1;i++){
            float temp=(float)(coordinates[i+1][1]-coordinates[i][1])/(coordinates[i+1][0]-coordinates[i][0]);
            if(slope!=temp){
                return false;
            }
            slope=temp;
        }
        return true;
    }
};