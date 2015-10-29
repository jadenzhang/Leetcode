class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (!board.size() || !board[0].size()) return;
        int row = board.size(), col = board[0].size();
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                int sum = findNum(board,i,j);
                if (board[i][j]==1 && sum<2) board[i][j]=2;
                else if (board[i][j]==1 && (sum==2 || sum==3)) continue;
                else if (board[i][j]==1 && sum>3) board[i][j]=2;
                else if (board[i][j]==0 && sum==3) board[i][j]=3;
            }
        }
        
        for (int i=0;i<row;i++){
            for (int j=0;j<col;j++){
                board[i][j]=board[i][j] % 2;
            }
        }
    }
    
    int findNum(vector<vector<int>> &board,int i, int j){
        int lives=0;
        int m=board.size(),n=board[0].size();
        for (int a=i-1;a<=i+1;a++){
            for (int b=j-1;b<=j+1;b++){
                if (a>=0 && b>=0 && a<board.size() && b<board[0].size()){
                    if ((board[a][b]==1 || board[a][b]==2) && (a!=i || b!=j) ){
                        lives++;
                    } 
                }
            }
        }
        
        return lives;
    }
};
