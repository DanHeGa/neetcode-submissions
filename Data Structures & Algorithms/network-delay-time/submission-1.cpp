class Solution {
public:
    void printDist(vector<int> dist) {
        for (int ele : dist) {
            cout << ele << " ";
        }
        cout << endl;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adjList(n);
        for(auto &time : times) {
            pair<int, int> neighbor = {time[2], time[1]}; //(cost, destiny)
            adjList[time[0]].push_back(neighbor);
        }

        vector<int> dist(n + 1, INT_MAX); 
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
        pair<int, int> startNodePair = {0, k};
        minheap.push(startNodePair);
        int needed = n;

        while(!minheap.empty()) {
            pair<int, int> currNodePair = minheap.top();
            int currNode = currNodePair.second;

            minheap.pop();

            for(auto &neigh : adjList[currNode]) {
                int neighCurrCost = neigh.first;
                int neighNode = neigh.second;

                if (dist[neighNode] > (dist[currNode] + neighCurrCost)) {
                    dist[neighNode] = dist[currNode] + neighCurrCost;
                    minheap.push(neigh);
                    cout << "Needed: " << needed << endl;
                    needed--;
                }
            }
        }
        printDist(dist);
        cout << "Need: " << needed << endl;
        int minTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] != INT_MAX) {
                minTime = max(minTime, dist[i]);
            } else {
                return -1;
            }
        }

        return minTime;

    }
};
