class TrieNode {
    public:
        TrieNode* children[26] = {nullptr};
        int isEnd = -1;

        void insertWord(string word, int wIndex) {
            TrieNode* curr = this;
            for (char letter : word) {
                int letterIdx = letter - 'a';

                if (!curr->children[letterIdx]) {
                    curr->children[letterIdx] = new TrieNode();
                }

                curr = curr->children[letterIdx];
            }

            curr->isEnd = wIndex;
        }
};

class Solution {
public:
    vector<string> res;
    TrieNode* root = new TrieNode();

    void dfs(int i, int j, TrieNode* curr, vector<vector<char>>& board, vector<string>& words) {
        int letter = board[i][j];
        int letterIdx = letter - 'a';

        //check if child actually exists
        if (!curr->children[letterIdx]) {
            return;
        }

        //move curr pointer, because right here it's in the parent
        curr = curr->children[letterIdx];
        
        //check if we are at the end of the word
        if (curr->isEnd != -1) {
            res.push_back(words[curr->isEnd]);
            curr->isEnd = -1; //avoid repeted
        }

        //check as visited
        char orgLetter = board[i][j];
        board[i][j] = '0';

        vector<int> pairWise = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int row = i + pairWise[k];
            int col = j + pairWise[k + 1];

            if (col >= 0 && col < board[0].size() && row >= 0 && row < board.size() && board[row][col] != '0') {
                dfs(row, col, curr, board, words);
            }
        }

        board[i][j] = orgLetter;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //1. fill trie
        for (int i = 0; i < words.size(); i++) {
            root->insertWord(words[i], i);
        }

        int rows = board.size();
        int cols = board[0].size();
    
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                dfs(i, j, root, board, words);
            }
        } 

        return res;
    }
};
