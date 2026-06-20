#include <cmath>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>> pq; //per default organizes the max heap based on the first ele of the pair
        vector<vector<int>> res;

        int n = points.size();
        for (int i = 0; i < n; i++) {
            double distance = sqrt(pow(points[i][0] - 0,2) + pow(points[i][1] - 0, 2));
            
            pair<double, int> pt_dist = {distance, i};
            pq.push(pt_dist);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        while(pq.size() > 0) {
            pair<int, int> top_ele = pq.top();
            pq.pop();

            res.push_back(points[top_ele.second]);
        }

        return res;
    }
};
