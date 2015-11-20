class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        if (k==0) return ret;
        vector<int> sol;
        FindAll(k,n,1,sol,ret);
        return ret;
    }
    
    void FindAll(int k,int rest, int cur, vector<int> &sol, vector<vector<int>> &ret){
        if (k==0){
            if (rest == 0){
                ret.push_back(sol);
            }
            return;
        }
        
        
        for (int i=cur;i<10;i++){
            sol.push_back(i);
            FindAll(k-1,rest-i,i+1,sol,ret);
            sol.pop_back();
        }
    }
};
