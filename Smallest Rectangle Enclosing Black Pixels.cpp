class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.size()==0 || image[0].size()==0) return 0;
        dfs(image,x,y);
        return (maxX-minX+1)*(maxY-minY+1);
    }
    
    void dfs(vector<vector<char>> &image, int x, int y){
        if (x<0 || y<0 || x>=image.size() || y>=image[0].size() || image[x][y]=='0') return;
        image[x][y] = '0';
        minX = min(minX,x);
        minY = min(minY,y);
        maxX = max(maxX,x);
        maxY = max(maxY,y);
        dfs(image,x+1,y);
        dfs(image,x,y+1);
        dfs(image,x-1,y);
        dfs(image,x,y-1);
    }
private:
    int minX = INT_MAX;
    int minY = INT_MAX;
    int maxX = 0;
    int maxY = 0;
};
