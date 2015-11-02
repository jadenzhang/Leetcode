class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0 || matrix[0].size()==0) return false;
        int row = matrix.size()-1;
        int col = 0;
        while (row <= matrix.size()-1 && row >=0 && col<matrix[0].size() && col>=0){
            int cur = matrix[row][col];
            if (cur == target) return true;
            else if (target > cur) col++;
            else row--;
        }
        
        return false;
    }
};
