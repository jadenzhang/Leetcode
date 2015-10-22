class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (!obstacleGrid.size() || !obstacleGrid[0].size()) return 0;
        vector<vector<int>> dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size()));
        if (obstacleGrid[0][0]==1 || obstacleGrid.back().back()==1) return 0;
        dp[0][0]=1;
        for (int i=1;i<obstacleGrid.size();i++){
            dp[i][0]= obstacleGrid[i][0]==1? 0:dp[i-1][0];
        }
        
        for (int i=1;i<obstacleGrid[0].size();i++){
            dp[0][i]= obstacleGrid[0][i]==1? 0:dp[0][i-1];
        }
        
        for (int i=1;i<obstacleGrid.size();i++){
            for (int j=1;j<obstacleGrid[0].size();j++){
                dp[i][j]=obstacleGrid[i][j]==1? 0:dp[i-1][j]+dp[i][j-1];
            }
        }
        
        return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};
