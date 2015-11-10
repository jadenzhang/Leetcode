class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bit(32,0);
        for (auto a:nums){
            for (int i=0;i<32;i++){
                bit[i] += (a>>i) & 1;
            }
        }
        
        int ret = 0;
        for (int i=0;i<32;i++){
            ret += (bit[i]%3)<<i;
        }
        
        return ret;
    }
};
