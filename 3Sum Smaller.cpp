class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size()<3) return 0;
        int count=0;
        sort(nums.begin(),nums.end());
        for (int i=0;i<nums.size()-2;i++){
            int start=i+1;
            int end=nums.size()-1;
            while (start<end){
                if (nums[i]+nums[start]+nums[end]>=target){
                    end--;
                }
                else {
                    count +=end-start;
                    start++;
                }
            }
        }
        
        return count;
    }
};
