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
       vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {            
           vector<Interval> res;
           bool isInsert=false;
           for (auto a:intervals){
               if (isInsert){
                   res.push_back(a);
               }
               else if (newInterval.end < a.start){
                   isInsert=true;
                   res.push_back(newInterval);
                   res.push_back(a);
               }
               else if (overlap(newInterval,a)){
                   newInterval.start = min(newInterval.start,a.start);
                   newInterval.end = max(newInterval.end,a.end);
               }
               
               else res.push_back(a);
           }
           
           if (!isInsert) res.push_back(newInterval);
           return res;
       }
       
       bool overlap(Interval a, Interval b){
           if (a.start>b.start){
               Interval temp=b;
               b=a;
               a=temp;
           }
           if (a.end >= b.start) return true;
           else return false;
       }
    
};
