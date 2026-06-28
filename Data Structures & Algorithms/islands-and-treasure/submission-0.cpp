class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q; //get treasure cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            pair<int, int> currCell = q.front();
            q.pop();

            vector<int> pairWise = {-1, 0, 1, 0, -1};
            int currRow = currCell.first;
            int currCol = currCell.second;
            for (int k = 0; k < 4; k++) {
                int newRow = currRow + pairWise[k];
                int newCol = currCol + pairWise[k + 1];

                int op = grid[currRow][currCol] + 1;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] != -1 
                    && op < grid[newRow][newCol]) {
                    grid[newRow][newCol] = op;
                    q.push({newRow, newCol});
                }
            }
        }
    }
};
