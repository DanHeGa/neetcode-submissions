class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> adjMatrix(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) { //build adj matrix
            int xi = points[i][0];
            int yi = points[i][1];
            for (int j = i + 1; j < n; j++){
                int xj = points[j][0];
                int yj = points[j][1];
                int distance =  abs(xi - xj) + abs(yi - yj);
                adjMatrix[i][j] = adjMatrix[j][i] = distance; //remember it's a bidirectional graph
            }
        }

        //initialize min distance and visited vector
        vector<int> minDist(n, INT_MAX); //min dist to current MST
        vector<bool> visited(n, false);

        minDist[0] = 0;
        int ans = 0; //initialize answer var

        //main prim loops
        for (int i = 0; i < n; i++) {
            //get closer pt to current MST
            int closestPt = -1; //initialize in -1 each loop to avoid cycles
            for (int k = 0; k < n; k++) {
                if (!visited[k] && (closestPt == -1 || minDist[k] < minDist[closestPt])) {
                    closestPt = k;
                }
            }

            //set as visited && add closestPt cost to currAns
            visited[closestPt] = true;
            ans += minDist[closestPt];

            //update minDist vector cuase u found a new closestPt
            for (int m = 0; m < n; m++) {
                if (!visited[m]) { //only update if not visited, because if already visited, it already has the min distance required
                    minDist[m] = min(minDist[m], adjMatrix[closestPt][m]);
                }
            }
        }

        return ans;
    }
};
