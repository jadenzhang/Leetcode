class Solution {
public:
    bool canJump(vector<int>& nums) {
        int MaxIndex = 0;
        for (int i=0;i<nums.size();i++){
            if (i>MaxIndex || MaxIndex>=nums.size()-1) break;
            MaxIndex = max(MaxIndex, i+nums[i]);
        }
        
        return (MaxIndex>=nums.size-1)? true:false;
    }
};
