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


//Solution 2

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
        int n = intervals.size();
        if (n==0 || n==1) return intervals;
        int len = 0;
        sort(intervals.begin(),intervals.end(),[](Interval A, Interval B){return A.start<B.start;});
        for (int i=0;i+1<n;i++){
            if(intervals[i].end < intervals[i+1].start){
                intervals[len] = intervals[i];
                len++;
            }
            else{
                intervals[i+1].start = min(intervals[i].start,intervals[i+1].start);
                intervals[i+1].end = max(intervals[i].end,intervals[i+1].end);
            }
        }
        intervals[len++] = intervals.back();
        intervals.resize(len);
        return intervals;
    }
};
