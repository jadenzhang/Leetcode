class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        vector<int> dp(row);
        for (int i=0;i<row;i++) dp[i]=triangle[row-1][i];
        for (int i=row-2;i>=0;i--){
            for (int j=0;j<=i;j++){
                dp[j]=triangle[i][j]+min(dp[j],dp[j+1]);
            }
        }
        
        return dp[0];
    }
};
