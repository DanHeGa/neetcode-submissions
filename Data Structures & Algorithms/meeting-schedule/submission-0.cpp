/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b){
            return a.start < b.start;
        });

        int prevEnd = intervals[0].end;

        for(int i = 1; i < intervals.size(); i++) {
            if (prevEnd > intervals[i].start) {
                return false;
            } else {
                prevEnd = intervals[i].end;
            }
        }

        return true;
    }
};
