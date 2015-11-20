class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0 || matrix[0].size()==0) return false;
        int n = matrix.size(), m = matrix[0].size();
        
        int up = 0, down = n-1;
        int row;
        while (up <= down){
            int mid = up + (down-up)/2;
            if (matrix[mid][0]==target) return true;
            if (matrix[mid][0] > target) down = mid-1;
            else up = mid+1;
        }
        
        row = down<0? 0:down;
        
        int left = 0, right = m-1;
        while (left <= right){
            int mid = left + (right-left)/2;
            if (matrix[row][mid]==target) return true;
            if (matrix[row][mid]>target) right = mid-1;
            else left = mid+1;
        }
        
        return false;
    }
};
