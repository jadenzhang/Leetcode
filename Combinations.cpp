class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (k==0) return ret;
        vector<int> sol;
        FindAll(n,k,1,sol,ret);
        return ret;
    }
    
    void FindAll(int n, int k, int cur, vector<int> &sol, vector<vector<int>> &ret){
        for (int i=cur;i<=n;i++){
            sol.push_back(i);
            if (sol.size()==k) ret.push_back(sol);
            FindAll(n,k,i+1,sol,ret);
            sol.pop_back();
        }
    }
};
