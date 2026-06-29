class Solution {
public:
    // void print(vector<vector<char>>& board) {
    //     for (int i = 0; i < board.size(); i++) {
    //         for (int j = 0; j < board[0].size(); j++) {
    //             cout << board[i][j] << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    
    int rows, cols;
    void solve(vector<vector<char>>& board) {
        bfs(board);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == 'T'){
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board) {
        queue<pair<int, int>> cornerCoors;

        rows = board.size();
        cols = board[0].size();
        //get corner 'O' to start multi origin BFS
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if ((i == 0 || i == rows - 1 || j == 0 || j == cols - 1) && board[i][j] == 'O'){
                    cornerCoors.push({i, j});
                }
            }
        }

        while (!cornerCoors.empty()) {
            pair<int, int> currCoor = cornerCoors.front();
            cout << "queue-> " << "( " << currCoor.first << ", " << currCoor.second << " )" << endl;
            cornerCoors.pop();

            int currRow = currCoor.first;
            int currCol = currCoor.second;
            board[currRow][currCol] = 'T';

            vector<int> pairWise = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; k++) {
                int newRow = currRow + pairWise[k];
                int newCol = currCol + pairWise[k + 1];

                if (newRow < rows && newRow >= 0 && newCol < cols && newCol >= 0 &&
                board[newRow][newCol] == 'O'){
                    cornerCoors.push({newRow, newCol});
                }
            }
            // print(board);
        }

    }

};