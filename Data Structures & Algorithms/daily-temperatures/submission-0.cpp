class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> stk;
        vector<int> res(n);

        for (int i = n - 1; i >= 0; i--) {
            //get to the next warmer day
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()]) {
                stk.pop();
            }

            //if stk is not empty, there is a next warmer day
            if (!stk.empty()) {
                cout << "Top: " << stk.top() << " res[i] -> " << stk.top() - i << endl;
                res[i] = stk.top() - i;
            }

            stk.push(i);

        }

        return res;
    }
};
