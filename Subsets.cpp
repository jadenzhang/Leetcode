class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> sol;
        res.push_back(sol);
        tool(nums,sol,res,0);
        return res;
    }
    
    void tool(vector<int>& nums, vector<int>& sol, vector<vector<int>> &res, int start){
        for (int i=start;i<nums.size();i++){
            sol.push_back(nums[i]);
            res.push_back(sol);
            tool(nums,sol,res,i+1);
            sol.pop_back();
        }
    }
};
