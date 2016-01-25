class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max;
        queue<int> window;
        int n = nums.size();
        deque<int> maxs;
        
        for (int i=0;i<n;i++){
            window.push(nums[i]);
            
            while (!maxs.empty()){
                if (nums[i]>maxs.back()) maxs.pop_back();
                else break;
            }
            
            maxs.push_back(nums[i]);
            
            if (window.size() == k){
                max.push_back(maxs.front());
                int out = window.front();
                window.pop();
                if (out == maxs.front()) maxs.pop_front();
            }
        }
        
        return max;
    }
};
