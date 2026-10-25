class Solution {
public:
    // int lis(int prevIdx, int currIdx, vector<int> sub, vector<int>& nums) {
    //     if (currIdx > nums.size()) {
    //         return 0;
    //     }
        
    //     //if bigger curr than prev, include it in current sub
    //     if (nums[currIdx] > nums[prevIdx]) {
    //         sub.push_back(nums[curr_idx]);
    //         lis(currIdx, currIdx + 1, sub, nums);
    //         sub.pop_back();
    //     }

    //     lis(prev, currIdx + 1, sub, nums);

    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxEle = 0;
        for (int ele : dp) {
            maxEle = max(maxEle, ele);
        }

        return maxEle;
    }
};
