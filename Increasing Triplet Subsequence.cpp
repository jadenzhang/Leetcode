class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3) return false;
        int min = nums[0];
        int mid = INT_MIN;
        int n = nums.size();
        
        for (int i=1;i<n;i++){
            if (nums[i]<=min) min = nums[i];
            else{
                if (mid == INT_MIN || nums[i]<=mid) mid = nums[i];
                else return true;
            }
        }
        
        return false;
    }
};
