class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) return nums.empty() ? 0 : nums[0];
        return max(tool(nums, 0, nums.size() - 1), tool(nums, 1, nums.size()));
    }
    
    int tool(vector<int>& nums, int left, int right){
        if (right-left<=1) return max(nums[left],nums[right-1]);
        vector<int> dp(right,0);
        dp[left]=nums[left];
        dp[left+1]=max(nums[left],nums[left+1]);
        for (int i=left+2;i<right;i++){
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp.back();
    }
};
