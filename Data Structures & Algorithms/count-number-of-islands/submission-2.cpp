class Solution {
public:
 
    bool dfs(int i, int j, vector<vector<char>>& grid) {
        if (grid[i][j] == '0'){
            return false;
        }

        grid[i][j] = '0';

        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> pairWise = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int row = i + pairWise[k];
            int col = j + pairWise[k + 1];
            if (row >= 0 && row < rows && col >= 0 && col < cols && grid[row][col] != '0') {
                dfs(row, col, grid);
            }
        }

        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    islands++;
                }
            }
        }

        return islands;
    }

};


/*

["0","1","1","1","0"],
["0","1","0","1","0"],
["1","1","0","0","0"],
["0","0","0","0","0"]

*/


