class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (!nums.size()) return 0;
        int res=nums.size()+1;
        int sum=0;
        for (int i=0,start=0;i<nums.size();i++){
            sum+=nums[i];
            while (sum>=s){
                if ((sum-nums[start])>=s){
                    sum -= nums[start];
                    start++;
                }
                else{
                    if (res>i-start) res=i-start+1;
                    sum -= nums[start];
                    start++;
                }
            }
            
        }
        
        return res==nums.size()+1? 0:res;
    }
};
