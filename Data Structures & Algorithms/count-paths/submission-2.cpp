class Solution {
public:
    int count = 0;
    void print(vector<vector<int>> &memo) {
        for (int i = 0; i < memo.size(); i++) {
            for (int j = 0; j < memo[0].size(); j++) {
                cout << memo[i][j] << " ";
            }
            cout << endl;
        }
    }
    int dfs(int i, int j, int &m, int &n, vector<vector<int>> &memo){
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = dfs(i, j + 1, m, n, memo) + dfs(i + 1, j, m, n, memo);

        return memo[i][j];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        int res = dfs(0, 0, m, n, memo);
        print(memo);
        return res;
    }
};
 