class Solution {
public:
    int dfsLis(int prev, int curr, vector<int>& nums, vector<vector<int>> &memo) {
        if (curr == nums.size()) {
            return 0;
        }

        if (memo[curr][prev + 1] != -1) {
            return memo[curr][prev + 1];
        }

        int take = 0;
        if (prev == -1 || nums[prev] < nums[curr]) {
            take = 1 + dfsLis(curr, curr + 1, nums, memo);
        }

        int skip = dfsLis(prev, curr + 1, nums, memo);
        memo[curr][prev + 1] = max(take, skip);
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        return dfsLis(-1, 0, nums, memo);
    }
};

/*
- without memoization, the solution is O(2^n) time, and O(n) space, due to the recursive stack.
*/