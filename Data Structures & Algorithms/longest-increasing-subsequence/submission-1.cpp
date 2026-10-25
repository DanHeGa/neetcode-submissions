class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // each position dp[i], represents the longest increasing subsequece at that point 
        vector<int> dp(n, 1); //O(n) space

        for (int i = 1; i < n; i++) { //O(n^2) time
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxEle = 0;
        for (int ele : dp) { //O(n) time
            maxEle = max(maxEle, ele);
        }

        return maxEle;
    }
};
