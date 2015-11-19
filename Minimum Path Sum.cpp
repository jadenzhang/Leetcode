class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()==0 || grid[0].size()==0) return 0;
        vector<int> last(grid[0].size(),0);
        vector<int> cur(grid[0].size(),0);
        last[0] = grid[0][0];
        for (int i=1;i<grid[0].size();i++) last[i] = last[i-1]+grid[0][i];
        for (int i=1;i<grid.size();i++){
            cur[0]=last[0]+grid[i][0];
            for (int j=1;j<grid[0].size();j++){
                cur[j]=min(last[j],cur[j-1])+grid[i][j];
            }
            last = cur;
        }
        
        return last[grid[0].size()-1];
    }
};

/*class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()==0 || grid[0].size()==0) return 0;
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size()));
        dp[0][0] = grid[0][0];
        for (int i=1;i<grid.size();i++) dp[i][0] = dp[i-1][0]+grid[i][0];
        for (int i=1;i<grid[0].size();i++) dp[0][i] = dp[0][i-1]+grid[0][i];
        
        for (int i=1;i<grid.size();i++){
            for (int j=1;j<grid[0].size();j++){
                dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[grid.size()-1][grid[0].size()-1];
    }
};*/
