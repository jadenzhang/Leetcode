class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    /*{
        vector<int> v1(nums.size());
        vector<int> v2(nums.size());
        v1[0]=1;
        for (int i=1;i<nums.size();i++){
            v1[i]=nums[i-1]*v1[i-1];
        }
        
        v2[nums.size()-1]=1;
        for (int i=nums.size()-2;i>=0;i--){
            v2[i]=v2[i+1]*nums[i+1];
        }
        
        for (int i=0;i<nums.size();i++){
            v1[i] *= v2[i];
        }
        
        return v1;
    }*/
    // O(1) space
    {
        vector<int> res(nums.size());
        int p;
        res[0]=1;
        for (int i=1;i<nums.size();i++){
            res[i]=res[i-1]*nums[i-1];
        }
        p=1;
        for (int i=nums.size()-2;i>=0;i--){
            p=p*nums[i+1];
            res[i]=p*res[i];
        }
        
        return res;
    }
};
