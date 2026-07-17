class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> tmpDist = dist;
            for (auto &flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int cost = flight[2];

                if (dist[from] == INT_MAX) continue; //we want to avoid those negative values in this case

                if (tmpDist[to] > dist[from] + cost) {
                    tmpDist[to] = dist[from] + cost;
                }
            }

            dist = tmpDist;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
