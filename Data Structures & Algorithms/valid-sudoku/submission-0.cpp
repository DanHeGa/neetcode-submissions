class Solution {
public:
    struct pair_hash{
        template <class T1, class T2>
        std::size_t operator () (std::pair<T1, T2> const &v) const
        {
            auto h1 = std::hash<T1>()(v.first);  
            auto h2 = std::hash<T2>()(v.second);

            return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));    
        }
    };

    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<char>> rows, cols;
        unordered_map<pair<int, int>, set<char>, pair_hash> square;

        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.') continue;

                char curr = board[i][j];
                pair<int, int> currSqr = {i / 3, j / 3};
                if (rows[i].find(curr) != rows[i].end() || 
                    cols[j].find(curr) != cols[j].end() || 
                    square[currSqr].find(curr) != square[currSqr].end()
                ) { 
                    return false;
                }

                rows[i].insert(curr);
                cols[j].insert(curr);
                square[currSqr].insert(curr);
            }
        }

        return true;
    }
};
