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
    static bool compare(Interval &a, Interval &b){
        return a.start < b.start;
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size()==1||intervals.size()==0) return true;
        sort(intervals.begin(),intervals.end(),compare);
        for (int i=1;i<intervals.size();i++){
            if (intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};
