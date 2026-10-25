class Solution {
public:
    bool dfs(int idx, int currSum, vector<int>& nums, int &targetSum, vector<vector<int>> &memo) {
        if (currSum > targetSum || idx == nums.size()) {
            return false;
        }

        if (currSum == targetSum) {
            return true;
        }

        if (memo[idx][currSum] != -1) {
            return memo[idx][currSum];
        }

        bool include = dfs(idx + 1, currSum + nums[idx], nums, targetSum, memo);
        bool exclude = dfs(idx + 1, currSum, nums, targetSum, memo);

        memo[idx][currSum] = (include || exclude) ? 1 : 0;
        return (include || exclude) ? 1 : 0;
    }
    bool canPartition(vector<int>& nums) {
        //if nums sum is NOT even, return false
        int totalSum = 0;
        for (int ele : nums) {
            totalSum += ele;
        }

        if (totalSum % 2 != 0) {
            return false;
        }

        int half = totalSum / 2;
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(half + 1, -1));
        return dfs(0, 0, nums, half, memo);
    }
};
