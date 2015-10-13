class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size()==0 || matrix[0].size()==0) return 0;
        int row=matrix.size();
        int col=matrix[0].size();
        int maxx=0;
        vector<vector<int>> dp(row,vector<int>(col,0));
        for (int i=0;i<row;i++){
            if (matrix[i][0]=='1'){
                dp[i][0]=1;
                maxx=1;
            }
        }
        
        for (int i=0;i<col;i++){
            if (matrix[0][i]=='1'){
                dp[0][i]=1;
                maxx=1;
            }
        }
        
        for (int i=1;i<row;i++){
            for (int j=1;j<col;j++){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]))+1;
                    maxx=max(maxx,dp[i][j]);
                }
            }
        }
        
        return maxx*maxx;
    }
};
