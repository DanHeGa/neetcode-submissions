class Solution {
public:

    int dfs(int i, int j, int &m, int &n, vector<vector<int>>& obstacleGrid, vector<vector<int>> &memo){
        if (i < 0 || i >= m || j < 0 || j >= n || obstacleGrid[i][j] == 1) {
            return 0;
        }

        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        memo[i][j] = dfs(i, j + 1, m, n, obstacleGrid, memo) + dfs(i + 1, j, m, n, obstacleGrid, memo);

        return memo[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> memo(n, vector<int>(m, -1));
        int res = dfs(0, 0, n, m, obstacleGrid, memo);
        return res;
    }
};