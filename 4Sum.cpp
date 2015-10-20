class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int, vector<pair<int,int>>> m;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                m[nums[i]+nums[j]].push_back(make_pair(i,j));
            }
        }
        
        for (int i=0;i<n-3;i++){
            if (i>0&&nums[i-1]==nums[i]) continue;
            for(int j=i+1;j<n-2;j++){
                if (j>i+1 && nums[j-1]==nums[j]) continue;
                int goal = target-nums[i]-nums[j];
                if (m.find(goal)!=m.end()){
                    vector<pair<int,int>> tem=m[goal];
                    bool isFirst=true;
                    for (auto a:tem){
                        if (a.first<=j) continue;
                        if (isFirst || nums[a.first] != res.back()[2]){
                            res.push_back(vector<int>{nums[i],nums[j],nums[a.first],nums[a.second]});
                            isFirst=false;
                        }
                    }
                }
            }
        }
        
        return res;
    }
};
