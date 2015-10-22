class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> sol;
        res.push_back(sol);
        FindAllSubsets(res,sol,nums,0);
        return res;
    }
    
    void FindAllSubsets(vector<vector<int>> &res, vector<int> sol, vector<int> nums, int start){
        for (int i=start;i<nums.size();i++){
            if (i>start && nums[i]==nums[i-1]) continue;
            sol.push_back(nums[i]);
            res.push_back(sol);
            FindAllSubsets(res,sol,nums,i+1);
            sol.pop_back();
        }
    }
};
