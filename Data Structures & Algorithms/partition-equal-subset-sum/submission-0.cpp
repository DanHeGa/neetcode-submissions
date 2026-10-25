class Solution {
public:

    // bool dfs(int &targetSum, int currSum, int idx, vector<int>& nums) {
    //     if (idx == nums.size()) {
    //         return false;
    //     }

    //     if (currSum == targetSum) {
    //         return true;
    //     }

    //     //decide wether to use it or not (in the current sum)
    //     if (currSum + nums[idx] <= targetSum) {
    //         return dfs(targetSum, currSum + nums[idx], idx + 1, nums);
    //     } else {
    //         return dfs(targetSum, currSum, idx + 1, nums);
    //     }
    // }

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
        vector<vector<bool>> dp(n + 1, vector<bool>(half + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= half; j++) {
                int currVal = nums[i - 1];
                dp[i][j] = dp[i - 1][j] || (j >= currVal && dp[i - 1][j - currVal]);
            }
        }

        return dp[n][half]; //see it it was feasible to form half with n values
    }
};
