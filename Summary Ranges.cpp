class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        long begin,end;
        string tem;
        vector<string> result;
        long diff;
        if(nums.size()==0) return result;
        if(nums.size()==1){
            result.push_back(to_string(nums[0]));
            return result;
        }
        begin=nums[0];
        for(int i=1;i<nums.size();i++){
            diff=(long)nums[i]-(long)nums[i-1];
            if(diff>1){
                end=nums[i-1];
                if(end==begin) result.push_back(to_string(end));
                else result.push_back(to_string(begin)+"->"+to_string(end));
                begin=nums[i];
            }
            
            if (i==nums.size()-1){
                end=nums[i];
                if(end==begin) result.push_back(to_string(end));
                else result.push_back(to_string(begin)+"->"+to_string(end));
            }
        }
        
        return result;
    }
};
