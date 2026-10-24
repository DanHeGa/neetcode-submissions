class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true)); //diag should be positive

        int maxLen = 1;
        int maxCandit = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j]){ //if found a palindrome
                    if (j - i + 1 > maxLen) {
                        maxLen = j - i + 1;
                        maxCandit = i;
                    }
                }
            }
        }

        cout << maxCandit << " with len = " << maxLen << endl;

        string res = s.substr(maxCandit, maxLen);
        return res;
    }
};
