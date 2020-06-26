/*If we pick a side of our polygon, it can form n - 2 triangles. Each such triangle forms 2 sub-polygons. We can analyze n - 2 triangles, and get the minimum score for sub-polygons using the recursion.
image
This is how this procedure looks for a sub-polygon (filled with diagonal pattern above).

image

Top-Down Solution
• Fix one side of the polygon i, j and move k within (i, j).
• Calculate score of the i, k, j "orange" triangle.
• Add the score of the "green" polygon i, k using recursion.
• Add the score of the "blue" polygon k, j using recursion.
• Use memoisation to remember minimum scores for each sub-polygons.
*/

class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        int n = A.size();
        int dp[n][n] = {};
        for (int sz = 2; sz < n; sz++) {
            for (int i = 0; i + sz < n; i++) {
                int j = i + sz;
                dp[i][j] = 1e9;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], A[i]*A[j]*A[k] + dp[i][k] + dp[k][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};