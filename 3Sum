class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> solutions;
        for (int i=0;i<nums.size();i++){
            int target=0-nums[i];
            int start=i+1, end=nums.size()-1;
            while (start < end){
                if (nums[start]+nums[end] == target){
                    vector<int> result;
                    result.push_back(nums[i]);
                    result.push_back(nums[start]);
                    result.push_back(nums[end]);
                    
                    solutions.push_back(result);
                    start++;end--;
                    
                    while(start<end && nums[start-1]==nums[start]) start++;
                    while(start<end && nums[end+1]==nums[end]) end--;
                }
                
                else if (nums[start]+nums[end] < target) start++;
                else end--;
            }
            
            while(i<nums.size()-1 && nums[i]==nums[i+1]) i++;   
        }
        return solutions;
    }
};
