class Solution {
public:
    vector<vector<string>> res;

    void dfs(int i, string word, vector<string>& sub, vector<vector<bool>>& isPalindrome) {
        if (i == word.length()) {
            res.push_back(sub);
            return;
        }

        for (int j = i; j < word.length(); j++) {
            if (isPalindrome[i][j]) {
                sub.push_back(word.substr(i, j - i + 1));
                dfs(j + 1, word, sub, isPalindrome);
                sub.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, true));
        vector<string> sub; 

        for (int i = n - 1; i >= 0; i--) { //initialize dp table to know if a word is palindrome or not.
            for (int j = i + 1; j < n; j++) {
                isPalindrome[i][j] = s[i] == s[j] && isPalindrome[i + 1][j - 1]; //check equal corner values as well as values within those limit chars
            }
        }
        
        dfs(0, s, sub, isPalindrome);
        return res;
    }
};
