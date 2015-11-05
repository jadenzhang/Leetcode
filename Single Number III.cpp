class Solution {
public:
    int findFirst1(int a){
        int index=0;
        while ((a&1)!=1){
            index++;
            a = a>>1;
        }
        return index;
    }
    
    bool is1(int a, int index){
        if ((a>>index)&1==1) return true;
        else return false;
    }
    vector<int> singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto a:nums) res ^= a;
        int index = findFirst1(res);
        int num1=0,num2=0;
        for (int i=0;i<nums.size();i++){
            if (is1(nums[i],index)) num1^=nums[i];
            else num2^=nums[i];
        }
        
        return {num1,num2};
    }
};
