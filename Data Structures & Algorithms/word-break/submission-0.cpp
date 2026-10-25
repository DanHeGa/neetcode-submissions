class TrieNode {
    public:
        TrieNode* children[26] = {nullptr};
        bool isFinal = false;

        void insert(string word) {
            TrieNode* curr = this;
            for (char c : word) {
                int idx = c - 'a';

                if (!curr->children[idx]) {
                    curr->children[idx] = new TrieNode();
                }

                curr = curr->children[idx];
            }

            curr->isFinal = true;
        }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //insert all word dict into Trie
        TrieNode* trie = new TrieNode();
        for (string word : wordDict) {
            trie->insert(word);
        }

        //keep looking existance within trie
        int n = s.length();
        vector<bool> dp(n + 1, false); //when a letter isFinal, dp[i + 1] will mean a new word can start from i + 1
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i]) { //is not viable to start from i a new word from wordDict
                continue;
            }
            
            TrieNode* curr = trie;
            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                if (curr->children[idx] == nullptr) {
                    break;
                }
                curr = curr->children[idx];

                if (curr->isFinal) {
                    dp[j + 1] = true;
                }
            }
        }
        
        return dp[n];
    }
};

/*
s = "applepenapple", wordDict = ["apple","pen","ape"]

*/
