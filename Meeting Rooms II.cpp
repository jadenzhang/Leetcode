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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        if (intervals.size()==0 || intervals.size()==1) return intervals.size();
        vector<vector<Interval>> rooms;
        for (int i=0;i<intervals.size();i++){
             int index = FindNoneOverlap(rooms,intervals[i]);
             if (index==-1 || rooms.empty()) rooms.push_back({intervals[i]});
             else rooms[index].push_back(intervals[i]);
        }
        
        return rooms.size();
    }
    
private:
    static bool compare(Interval &a, Interval &b){
        return a.start < b.start;
    }
    
    int FindNoneOverlap(vector<vector<Interval>> &rooms, Interval interval){
        for (int i=0;i<rooms.size();i++){
            if (interval.start >= rooms[i].back().end){
                return i;
            }
        }
        
        return -1;
    }
};
