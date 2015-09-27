class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        if (numRows==0) return result;
        result.push_back({1});
        if (numRows==1) return result;
        result.push_back({1,1});
        
        for (int i=2;i<numRows;i++){
            vector<int> tem(i+1);
            tem[0]=1;
            tem[i]=1;
            for (int j=1;j<i;j++){
                tem[j]=result[i-1][j-1]+result[i-1][j];
            }
            result.push_back(tem);
        }
        return result;
    }
};
