class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> sol;
        FindCombinations(ret,sol,0,0,candidates,target);
        return ret;
    }
    
    void FindCombinations(vector<vector<int>> &ret, vector<int> &sol, int start, int cur, vector<int>& candidates, int target){
        if (cur == target){
            ret.push_back(sol);
            return;
        }
        
        if (cur > target) return;
        
        for (int i=start;i<candidates.size();i++){
            sol.push_back(candidates[i]);
            FindCombinations(ret,sol,i+1,cur+candidates[i],candidates,target);
            sol.pop_back();
            while (i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
        }
    }
};
