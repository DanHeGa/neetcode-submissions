class Solution {
public:
    int rows, cols; 

    int helper(int i, int j, vector<vector<int>>& grid) {
        if (grid[i][j] == 0){
            return 0;
        }

        grid[i][j] = 0; //mark as visited
        int currArea = 1;
        vector<int> pairWise = {-1, 0, 1, 0, -1};
        for(int k = 0; k < 4; k++) {
            int newRow = i + pairWise[k];
            int newCol = j + pairWise[k + 1];
            
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                currArea += helper(newRow, newCol, grid);
            }
        }

        return currArea;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int maxSize = INT_MIN;
        for (int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                int iSize = helper(i, j, grid);
                maxSize = max(maxSize, iSize);
            }
        }

        return maxSize;
    }
};
