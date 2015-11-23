class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ret;
        vector<int> sol;
        FindAll(ret,sol,2,n,true);
        return ret;
    }
    
    void FindAll(vector<vector<int>> &ret, vector<int> &sol, int cur, int rest, bool isFirst){
        if (rest == 1){
            if (sol.size()>1) ret.push_back(sol);
            return;
        }
        for (int i=cur;i<=sqrt(rest);i++){
            sol.push_back(i);
            if (rest%i == 0) FindAll(ret,sol,i,rest/i,false);
            sol.pop_back();
        }
        
        if (!isFirst){
            sol.push_back(rest);
            ret.push_back(sol);
            sol.pop_back();
        }
    }
};
