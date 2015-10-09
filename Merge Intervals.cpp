/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        for (int i=0;i<intervals.size();i++){
            insert(res,intervals[i]);
        }
        return res;
    }
    
    void insert(vector<Interval>& res, Interval newinterval){
        vector<Interval>::iterator it=res.begin();
        while(it!=res.end()){
            if(newinterval.end < it->start){
                res.insert(it,newinterval);
                return;
            }
            
            else if (newinterval.start > it->end){
                it++;
                continue;
            }
            
            else{
                newinterval.start=min(newinterval.start,it->start);
                newinterval.end=max(newinterval.end,it->end);
                it=res.erase(it);
            }
        }
        
        res.insert(it,newinterval);

    }
};
