class Solution {
public:
    vector<string> res;
    void dfs(int n, string sub, int open, int close) {
        if (open == n && close == n) {
            res.push_back(sub);
            return;
        }
        if (open > close || open > n || close > n) {
            return;
        }

        dfs(n, sub + ')', open + 1, close);
        dfs(n, sub + '(', open, close + 1);
    }

    vector<string> generateParenthesis(int n) {
        string sub;
        dfs(n, sub, 0, 0);
        return res;
    }
};
