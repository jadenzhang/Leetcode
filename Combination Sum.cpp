class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> sol;
        sort(candidates.begin(),candidates.end());
        findAllcombinations(ret,sol,0,0,candidates,target);
        return ret;
    }
    
    void findAllcombinations(vector<vector<int>> &ret, vector<int> &sol, int cur,int pos ,vector<int> &candidates, int target){
        if (cur == target) ret.push_back(sol);
        if (cur > target) return;
        for (int i=pos;i<candidates.size();i++){
            sol.push_back(candidates[i]);
            findAllcombinations(ret,sol,cur+candidates[i],i,candidates,target);
            sol.pop_back();
        }
    }
};
