class Solution {
public:
    int rows, cols;
    bool dfs(int i, int j, int pos, vector<vector<char>>& board, string word) {
        if (pos == word.length() - 1) {
            return board[i][j] == word[pos];
        }

        if (board[i][j] != word[pos]) {
            return false;
        }

        char orgEle = board[i][j];
        board[i][j] = '0'; //marked as visited

        //check neighbors
        int pairs[5] = {-1, 0, 1, 0, -1}; //up, right, down, left pairwise
        for (int k = 0; k < 4; k++) {
            int row = i + pairs[k];
            int col = j + pairs[k + 1];
            
            //check limits and board cell disponibility
            if (row >= 0 && row < rows && col >= 0 && col < cols && board[row][col] != '0') {
                if (dfs(row, col, pos + 1, board, word)){
                    return true;
                }
            }
        }

        board[i][j] = orgEle;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }

        return false;
    }
};
