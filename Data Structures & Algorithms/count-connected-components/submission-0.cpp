class Solution {
public:
    int find(int node, vector<int>& parents) {
        if (parents[node] != node) {
            parents[node] = find(parents[node], parents);
        }
        return parents[node];
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<int> parents(n);
        iota(parents.begin(), parents.end(), 0); //[0, 1, 2, 3, 4]


        for (auto& edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            int root1 = find(node1, parents);
            int root2 = find(node2, parents);

            if (root1 == root2) {
                continue;
            }

            parents[root1] = root2;
            n--;
        }

        return n;
    }
};

/*
p = [0, 1, 2, 3, 5]


[0, 1]
*/