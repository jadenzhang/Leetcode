class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        range.push_back(findLeft(nums,target));
        range.push_back(findRight(nums,target));
        return range;
    }
    
    int findLeft(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        while (start<=end){
            int mid = start + (end - start)/2;
            if (nums[mid]>target) end = mid - 1;
            else if (nums[mid]<target) start = mid + 1;
            else end = mid - 1;
        }
        if (nums[start]==target) return start;
        else return -1;
    }
    
    int findRight(vector<int>& nums, int target){
        int start = 0, end = nums.size()-1;
        while (start<=end){
            int mid = start + (end - start)/2;
            if (nums[mid]>target) end = mid - 1;
            else if (nums[mid]<target) start = mid + 1;
            else start = mid + 1;
        }
        if (nums[end]==target) return end;
        else return -1;        
    }
};
