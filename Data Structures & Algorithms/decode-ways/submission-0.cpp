class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(s.length() + 1, 0);
        dp[0] = 1; //empty string can only do 1 decodement, do nothing (Mbappe special)

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] = dp[i - 1];
            }

            if (i > 1 && s[i - 2] != '0' && (s.substr(i - 2, 2) <= "26")) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[n];
    }
};

/*
0123
1 201

1 20 1
120 1

[       ]
 0 1 2 3 

010
if num in pos i == 0, i++ (move i)
if num in pos i + 1 == 0 while in i, move i += 2;

*/


