class Solution {
public:
    vector<vector<string>> res;
    vector<string> board;

    bool validSpot(int row, int col) {
        //check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        //check diagonal
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q'){
                return false;
            }
        }

        return true;
    }

    void addQueens(int row, int n) {
        //base condition
        if (row == n) {
            res.push_back(board);
            return;
        }

        //see each column within a row
        for (int j = 0; j < n; j++) {
            if (validSpot(row, j)) {
                board[row][j] = 'Q';
                addQueens(row + 1, n);
                board[row][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        board.resize(n, string(n, '.'));
        int row = 0;
        addQueens(row, n);
        return res;
    }
};
