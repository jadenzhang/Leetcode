class Solution {
public:
    bool check(char ch, bool* hash){
        if (ch == '.') return true;
        if (hash[ch-'1']) return false;
        hash[ch-'1'] = true;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        bool hash[9];
        
        for (int i=0; i<9; i++){
            
            fill(hash,hash+9,false);
            for (int j=0; j<9;j++){
                if(!check(board[i][j],hash)) return false;
            }
            
            fill(hash,hash+9,false);
            for (int j=0; j<9; j++){
                if(!check(board[j][i],hash)) return false;
            }
        }
        
        for (int c=0;c<3;c++)
                for (int r=0;r<3;r++){
                   fill(hash,hash+9,false);
                   for (int col=c*3;col<c*3+3;col++)
                        for (int row=r*3;row<r*3+3;row++)
                            if (!check(board[row][col],hash)) return false; 
                }
        
        return true;
    }
};
