class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<int> sol;
        vector<vector<int>> allSol;
        findComb(n, 1, k, sol, allSol);
        return allSol;
    }
    
    void findComb(int n, int start, int k, vector<int> &sol, vector<vector<int>> &allSol) {
        if(k==0) {
            allSol.push_back(sol);
            return;
        }
        
        for(int i=start; i<=n-k+1; i++) {
            sol.push_back(i);
            findComb(n, i+1, k-1, sol, allSol);
            sol.pop_back();
        } 
    }    
};
/*class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (k==0) return ret;
        vector<int> sol;
        FindAll(n,k,1,sol,ret);
        return ret;
    }
    
    void FindAll(int n, int k, int cur, vector<int> &sol, vector<vector<int>> &ret){
        if (sol.size()==k){
            ret.push_back(sol);
            return;
        }
        for (int i=cur;i<=n;i++){
            sol.push_back(i);
            FindAll(n,k,i+1,sol,ret);
            sol.pop_back();
        }
    }
};*/
