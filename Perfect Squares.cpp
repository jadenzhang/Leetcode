class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        for (int i=0;i*i<=n;i++) dp[i*i]=1;
        
        for (int i=1;i<n;i++){
            for (int j=0;j*j<n;j++){
                if (i+j*j<=n) dp[i+j*j] = min(dp[i]+1,dp[i+j*j]);
            }
        }
        
        return dp[n];
    }
};
