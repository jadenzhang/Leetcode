class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<2) return 0;
        int dp[n];
        dp[0]=0;
        int profit=0;
        int minprice=prices[0];
        for (int i=1;i<n;i++){
            minprice=min(minprice,prices[i]);
            if (prices[i]-minprice>profit){
                profit=prices[i]-minprice;
            }
            dp[i]=profit;
        }
        profit=0;
        int res=dp[n-1];
        int maxprice=prices[n-1];
        for (int i=n-2;i>=0;i--){
            maxprice=max(maxprice,prices[i]);
            if (maxprice-prices[i]>profit){
                profit=maxprice-prices[i];
            }
            if (dp[i]+profit > res) res = dp[i]+profit;
        }
        
        return res;
    }
};
