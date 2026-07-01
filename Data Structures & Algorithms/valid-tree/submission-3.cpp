class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        
        vector<vector<int>> adjList(n);
        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }


        unordered_set<int> visited;
        queue<pair<int, int>> q;
        q.push({0, -1});

        while(!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();

            if (visited.find(node) != visited.end()) {
                return false;
            }

            visited.insert(node);

            for (int adj : adjList[node]) {
                if (adj == parent) continue;
                q.push({adj, node});
            }

            cout << endl;
        }

        return visited.size() == n;
    }
};
