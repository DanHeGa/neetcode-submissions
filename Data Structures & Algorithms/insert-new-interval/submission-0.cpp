class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> resIntervals;

        intervals.push_back(newInterval); //add new desird interval to intervals list
        sort(intervals.begin(), intervals.end());

        resIntervals.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            //check if overlap, if yes, define a new end point for that interval
            int currEndPoint = resIntervals.back()[1];
            if (currEndPoint >= intervals[i][0]) {
                resIntervals.back()[1] = max(intervals[i][1], currEndPoint);
            } else { //no overlap, add interval to resul array
                resIntervals.push_back(intervals[i]);
            }
        }

        return resIntervals;

    }
};
