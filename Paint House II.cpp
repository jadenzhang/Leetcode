class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (!costs.size() || !costs[0].size()) return 0;
        int house = costs.size();
        int color = costs[0].size();
        vector<int> res(color,INT_MAX);
        vector<int> tem(color);
        for (int i=0;i<color;i++) tem[i]=costs[0][i];
        
        for (int i=1;i<house;i++){
            for (int j=0;j<color;j++){
                res[j] = INT_MAX;// Important!!!
                for (int z=0;z<color;z++){
                    if (z!=j){
                        res[j]=min(tem[z]+costs[i][j],res[j]);
                    }
                }
            }
            
            for (int j=0;j<color;j++){
                tem[j]=res[j];
            }
        }
        int minCost=INT_MAX;
        for (int i=0;i<color;i++){
            minCost=min(minCost,tem[i]);
        }
        
        return minCost;
    }
};
