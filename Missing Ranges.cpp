class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int start,end;
        int index = lower;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==index) {
                index++;
                continue;
            }
            string s;
            start = index;
            index = nums[i];
            end = index-1;
            if (start == end){
                s.append(to_string(start));
                res.push_back(s);
            }
            
            else{
                s.append(to_string(start)+"->"+to_string(end));
                res.push_back(s);
            }
            index++;
        }
        
        if(index <= upper){
            if (upper == index) res.push_back(to_string(upper));
            else res.push_back(to_string(index)+"->"+to_string(upper));
        }
        
        return res;
    }
};
