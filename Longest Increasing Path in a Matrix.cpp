class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size()==0 || matrix[0].size()==0) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int Max = 0;
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                Max = max(Max,dfs(i,j,matrix,visited,INT_MIN));
            }
        }
        
        return Max;
    }
    
    int dfs(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &visited,int val){
        if (i<0 || i>=matrix.size() || j<0 || j>=matrix[0].size()) return 0;
        
        if (matrix[i][j]>val){
            if (visited[i][j]!=0) return visited[i][j];
            int l1 = dfs(i+1,j,matrix,visited,matrix[i][j])+1;
            int l2 = dfs(i,j+1,matrix,visited,matrix[i][j])+1;
            int l3 = dfs(i-1,j,matrix,visited,matrix[i][j])+1;
            int l4 = dfs(i,j-1,matrix,visited,matrix[i][j])+1;
            visited[i][j] = max(l1,max(l2,max(l3,l4)));
            return visited[i][j];
        }
        
        return 0;
    }
};
