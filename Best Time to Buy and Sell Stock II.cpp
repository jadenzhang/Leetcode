class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if (n<=1) return 0;
        int i=0;
        int profit=0;
        
        while (i<n-1){
            int buy,sell;
            
            while (i+1<n && prices[i]>=prices[i+1]) i++;
            buy=i;
            while (i+1<n && prices[i]<prices[i+1]) i++;
            sell=i;
            
            profit+=prices[sell]-prices[buy];
        }
        
        return profit;
    }
};
