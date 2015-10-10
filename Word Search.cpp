class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty()) return false;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if (tool(board,visited,i,j,0,word)) return true;
            }
        }
        return false;
    }
    
    bool tool(vector<vector<char>> &board, vector<vector<bool>> &visited, int row, int col, int index,string word){
        if (index==word.size()) return true;
        if (row<0 || col<0 || row>=board.size() || col>=board[0].size()||visited[row][col]|| board[row][col]!=word[index])
            return false;
        visited[row][col]=true;
        if (tool(board,visited,row-1,col,index+1,word)) return true;
        if (tool(board,visited,row+1,col,index+1,word)) return true;
        if (tool(board,visited,row,col+1,index+1,word)) return true;
        if (tool(board,visited,row,col-1,index+1,word)) return true;
        visited[row][col]=false;
        return false;
    }
};
