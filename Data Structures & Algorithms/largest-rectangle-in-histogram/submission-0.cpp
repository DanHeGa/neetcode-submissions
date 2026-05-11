class Solution {
public:

    void debugVec(vector<int> vec){
        for (int ele : vec) {
            cout << ele << " ";
        }
        cout << endl;
    }

    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        int n = heights.size();
        vector<int> minLeft(n, -1);
        vector<int> minRight(n, n);

        //leftMin work
        for (int i = 0; i < n; i++) {
            while(!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }

            //get min left value
            if (!stk.empty()) {
                minLeft[i] = stk.top();
            }

            stk.push(i);
        }

        //empty stk if necessary
        if (!stk.empty()) {
            while (!stk.empty()) {
                stk.pop();
            }
        }

        //rightMost work
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }

            if (!stk.empty()) {
                minRight[i] = stk.top();
            }

            stk.push(i);
        }

        //debug vectors 
        cout << "min lefts" << endl;
        debugVec(minLeft);
        cout << "min rights " << endl;
        debugVec(minRight);

        //get max rectangle area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int left = minLeft[i] + 1;
            int right = minRight[i] - 1;
            int area = heights[i] * ((right - left) + 1);
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
