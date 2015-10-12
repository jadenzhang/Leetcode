class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (!grid.size()||!grid[0].size()) return 0;
        int count=0;
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[i].size();j++){
                if (grid[i][j] != '1') continue;
                else{
                    count++;
                    tool(grid,i,j);
                }
            }
        }
        return count;
    }
    
    void tool(vector<vector<char>> &grid, int i, int j){
        if (i<0 || i>=grid.size()||j<0||j>=grid[0].size()) return;
        if (grid[i][j] != '1') return;
        grid[i][j]='2';
        tool(grid,i+1,j);
        tool(grid,i-1,j);
        tool(grid,i,j+1);
        tool(grid,i,j-1);
    }
};
