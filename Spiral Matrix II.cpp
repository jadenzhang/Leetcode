class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n));
        int val = 1;
        for (int i=0;i<n/2;i++){
            int last = n-1-i;
            for (int j=i;j<last;j++) ret[i][j]=val++;
            for (int j=i;j<last;j++) ret[j][last]=val++;
            for (int j=last;j>i;j--) ret[last][j]=val++;
            for (int j=last;j>i;j--) ret[j][i]=val++;
        }
        
        if (n%2) ret[n/2][n/2]=val;
        return ret;
    }
};
