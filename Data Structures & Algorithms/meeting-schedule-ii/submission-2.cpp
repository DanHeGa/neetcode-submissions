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
    int minMeetingRooms(vector<Interval>& intervals) {
        int maxEndTime = 0;
        for (Interval interval : intervals) {
            maxEndTime = max(maxEndTime, interval.end);
        }

        vector<int> schedule(maxEndTime + 1, 0);

        for (Interval inter : intervals) {
            schedule[inter.start] += 1;
            schedule[inter.end] -= 1;
        }

        int prefixSum = 0;
        int maxSum = 0;
        for (int i = 0; i < schedule.size(); i++) {
            prefixSum += schedule[i];
            maxSum = max(maxSum, prefixSum);
        }

        return maxSum;
    }
};
