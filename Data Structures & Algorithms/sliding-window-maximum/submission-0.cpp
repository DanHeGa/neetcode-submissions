class Solution {
public:
    //brute force approach
    //complexity: time = O(n * k) space = O(n - k + 1)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i <= n - k; i++) {
            int max = nums[i];
            for (int j = i; j < i + k; j++) {
                if (nums[j] > max) max = nums[j];
            }

            res.push_back(max);
        }

        return res;
    }
};
