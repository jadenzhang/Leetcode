class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sol;
        vector<bool> used(nums.size(),false);
        if (!nums.size()) return res;
        findper(nums,res,sol,used,0);
        return res;
    }
    
    void findper(vector<int> &nums, vector<vector<int>> &res, vector<int> &sol, vector<bool> &used, int deep){
        if (deep==nums.size()){
            res.push_back(sol);
            return;
        }
        for (int i=0;i<nums.size();i++){
            if (used[i]==false){
                used[i]=true;
                sol.push_back(nums[i]);
                findper(nums,res,sol,used,deep+1);
                sol.pop_back();
                used[i]=false;
            }
            else continue;
        }
    }
};
