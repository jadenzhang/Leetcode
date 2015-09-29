class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        if (k<=0) return;
        
        tool(nums,0,nums.size()-1);
        tool(nums,0,k-1);
        tool(nums,k,nums.size()-1);
    }
    
    void tool(vector<int>& s, int begin, int end){
        while (begin<end){
            int tem=s[begin];
            s[begin]=s[end];
            s[end]=tem;
            begin++;
            end--;
        }
    }
};
