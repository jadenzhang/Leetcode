class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=-1;
        int sum = 0;
        int maxlen = 0;
        
        for (int i=0;i<nums.size();i++){
            sum += nums[i];
            if (!m.count(sum)) m[sum] = i;
            if (m.count(sum-k)) maxlen = max(maxlen,i-m[sum-k]);
        }
        
        return maxlen;
    }
};
