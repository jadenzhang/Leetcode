class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        
        if (len == 0) return 0;
        int index = 0;
        for (int i=0;i<len;i++){
            
            if (nums[index] == nums[i]) continue;
            index++;
            nums[index] = nums[i];
        }
        
        return index+1;
    }
};
