class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size();
        int count=1,res=nums[0];
        for(int i=1;i<len;i++){
            if (nums[i]==res) count++;
            else if(count==0){
                count=1;
                res=nums[i];
            }
            else count--;
        }
        
        return res;
    }
};
