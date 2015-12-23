class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ar = A.size(), ac = A[0].size();
        int br = B.size(), bc = B[0].size();
        vector<vector<int>> A_nonzero(ar);
        vector<vector<int>> B_nonzero(bc);
        
        vector<vector<int>> ret(ar,vector<int>(bc,0));
        
        for (int i=0;i<ar;i++){
            for (int j=0;j<ac;j++){
                if (A[i][j]) A_nonzero[i].push_back(j);
            }
        }
        
        for (int i=0;i<bc;i++){
            for (int j=0;j<br;j++){
                if (B[j][i]) B_nonzero[i].push_back(j);
            }
        }
        
        
        for (int i=0;i<ar;i++){
            for (int j=0;j<bc;j++){
                int m = 0, n = 0;
                while (m < A_nonzero[i].size() && n < B_nonzero[j].size()){
                    int A_idx = A_nonzero[i][m];
                    int B_idx = B_nonzero[j][n];
                    if (A_idx == B_idx){
                        ret[i][j] += (A[i][A_idx] * B[B_idx][j]);
                        n++;
                        m++;
                    }
                    
                    else if (A_idx < B_idx) m++;
                    else n++;
                }
            }
        }
        
        return ret;
    }
};
