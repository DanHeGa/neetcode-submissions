class Solution {
public:
    int find(int x, unordered_map<int, int>& parents) {
        if (parents[x] == x) return x;
        return find(parents[x], parents);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> parents;

        //initialize parents map
        for(int i = 1; i <= n; i++) {
            parents[i] = i;
        }

        vector<int> res = {};
        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            int root1 = find(node1, parents);
            int root2 = find(node2, parents);

            cout << "n1: " << node1 << ", n2: " << node2 << endl;
            cout << "r1: " << root1 << ", r2: " << root2 << endl;

            if (root1 == root2) {
                res = {node1, node2};
                continue;
            }

            parents[root1] = root2;
        }

        return res;

    }
};
